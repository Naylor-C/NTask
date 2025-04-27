#ifndef GTKMM_FRAME_H
#define GTKMM_FRAME_H

#include <gtkmm.h>

class Frame : public Gtk::Window
{
public:
  Frame();
  virtual ~Frame();

protected:
  //Signal handlers:
  void on_button_quit();
  void on_treeview_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);

class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
      public:
      ModelColumns()
      { 
       add(columns_main); 
       add(columns_sub); 
      }

     Gtk::TreeModelColumn<Glib::ustring> columns_main;
     Gtk::TreeModelColumn<Glib::ustring> columns_sub;
  };

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;

  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Quit;
};

#endif

