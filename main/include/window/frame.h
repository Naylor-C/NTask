#include "config_frame.h"

Frame::Frame()
    m_VBox(Gtk::Orientation::VERTICAL),
    m_Button_Quit("Quit")
{
  set_title("Basic application");
  set_default_size(800, 400);

  m_VBox.set_margin(5);
  set_child(m_VBox);

  // Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.set_child(m_TreeView);

  // Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_ScrolledWindow.set_expand();

  m_VBox.append(m_ScrolledWindow);
  m_VBox.append(m_ButtonBox);

  m_ButtonBox.append(m_Button_Quit);
  m_ButtonBox.set_margin(5);
  m_Button_Quit.set_hexpand(true);
  m_Button_Quit.set_halign(Gtk::Align::END);
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
                                                       &Frame::on_button_quit));

  // Create the Tree model:
  m_refTreeModel = Gtk::TreeStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  // All the items to be reordered with drag-and-drop:
  m_TreeView.set_reorderable();

  // Fill the TreeView's model
  auto row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_name] = "Billy Bob";

  auto childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 11;
  childrow[m_Columns.m_col_name] = "Billy Bob Junior";

  childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 12;
  childrow[m_Columns.m_col_name] = "Sue Bob";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_name] = "Joey Jojo";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 3;
  row[m_Columns.m_col_name] = "Rob McRoberts";

  childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 31;
  childrow[m_Columns.m_col_name] = "Xavier McRoberts";

  // Add the TreeView's view columns:
  m_TreeView.append_column("ID", m_Columns.m_col_id);
  m_TreeView.append_column("Name", m_Columns.m_col_name);

  // Connect signal:
  m_TreeView.signal_row_activated().connect(sigc::mem_fun(*this,
                                                          &ExampleWindow::on_treeview_row_activated));
}

void Frame::on_button_quit()
{
  set_visible(false);
}

void Frame::on_treeview_row_activated(const Gtk::TreeModel::Path &path,
                                      Gtk::TreeViewColumn * /* column */)
{
  const auto iter = m_refTreeModel->get_iter(path);
  if (iter)
  {
    const auto row = *iter;
    std::cout << "Row activated: ID=" << row[m_Columns.m_col_id] << ", Name="
              << row[m_Columns.m_col_name] << std::endl;
  }
}
