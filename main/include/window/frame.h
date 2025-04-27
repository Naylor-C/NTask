#include <gtkmm.h>

class Frame : public Gtk::Window
{
public:
  Frame();
  virtual ~Frame();
};

Frame::Frame()
{
  set_title("Basic application");
  set_default_size(200, 200);
}

