#include <gtk/gtk.h>

enum
{
    calendar_show_header,
    calendar_show_days,
    calendar_month_change,
    calendar_show_week
};

GtkWidget *calendar;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void on_heading_toggle(GtkWidget *checkbutton, GtkWidget *calendar)
{
    printf("Test");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    calendar = gtk_calendar_new();
    gtk_box_pack_start(GTK_BOX(hbox), calendar, TRUE, TRUE, 0);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(hbox), vbox, TRUE, FALSE, 0);

    GtkWidget *checkbutton;

    checkbutton = gtk_check_button_new_with_label("Show Heading");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton), TRUE);
    g_signal_connect(GTK_TOGGLE_BUTTON(checkbutton), "toggled", G_CALLBACK(on_heading_toggle), calendar);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, FALSE, FALSE, 0);
    checkbutton = gtk_check_button_new_with_label("Show Day Names");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton), TRUE);
    g_signal_connect(GTK_TOGGLE_BUTTON(checkbutton), "toggled", G_CALLBACK(on_show_days_toggle), calendar);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, FALSE, FALSE, 0);
    checkbutton = gtk_check_button_new_with_label("Show Week Numbers");
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, FALSE, FALSE, 0);
    g_signal_connect(GTK_TOGGLE_BUTTON(checkbutton), "toggled", G_CALLBACK(on_show_weeks_toggle), calendar);
    checkbutton = gtk_check_button_new_with_label("Prevent Month/Year Change");
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, FALSE, FALSE, 0);
    g_signal_connect(GTK_TOGGLE_BUTTON(checkbutton), "toggled", G_CALLBACK(on_no_change_toggle), calendar);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
