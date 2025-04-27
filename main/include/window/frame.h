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
};


