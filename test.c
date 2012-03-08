#include "test.h"
#ifndef ELM_LIB_QUICKLAUNCH

void
design_exit(void)
{
  elm_exit();
}

static void
_test_print(void *data,
	    Evas_Object *obj,
	    const char *emission,
	    const char *source)
{
  printf("C'est moi %s\n", source);
}

static void
_design_cb_win_del(void        *data __UNUSED__,
                   Evas_Object *obj __UNUSED__,
                   void        *event_info __UNUSED__)
{
  design_exit();
}

EAPI int
elm_main(int argc __UNUSED__,
         char **argv __UNUSED__)
{
  Elm_Theme *th;
  Evas_Object *win, *bg, *lay, *but1, *but2;

  th = elm_theme_default_get();
  elm_theme_overlay_add(th, "./test.edj");
  elm_theme_full_flush();

  win = elm_win_add(NULL, "main", ELM_WIN_BASIC);
  elm_win_title_set(win, "Test");
  evas_object_smart_callback_add(win, "delete,request", _design_cb_win_del, NULL);

  bg = elm_bg_add(win);
  evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
  elm_win_resize_object_add(win, bg);
  evas_object_show(bg);

  lay = elm_layout_add(win);
  evas_object_size_hint_weight_set(lay, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
  elm_layout_theme_set(lay, "layout", "application", "test");

  but1 = elm_button_add(win);
  elm_object_part_content_set(lay, "elm.swallow.view", but1);

  but2 = elm_button_add(win);
  elm_object_part_content_set(lay, "elm.swallow.panel", but2);

  evas_object_pointer_mode_set(but1, EVAS_OBJECT_POINTER_MODE_NOGRAB);
  evas_object_pointer_mode_set(but2, EVAS_OBJECT_POINTER_MODE_NOGRAB);

  edje_object_signal_callback_add(elm_layout_edje_get(lay),
				  "signal_test_print",
				  "view.bg",
				  _test_print,
				  NULL);
  edje_object_signal_callback_add(elm_layout_edje_get(lay),
				  "signal_test_print",
				  "panel.bg",
				  _test_print,
				  NULL);

  elm_win_resize_object_add(win, lay);
  evas_object_show(lay);
  evas_object_show(win);
  evas_object_size_hint_min_set(win, 800, 600);
  evas_object_resize(win, 1024, 800);

  elm_run();
  elm_shutdown();
  return 0;
}
#endif
ELM_MAIN()
