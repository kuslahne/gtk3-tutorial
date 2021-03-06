TreeViewColumn
==============
The TreeViewColumn object is added into a :doc:`treeview`, and is used to represent a column. It is assigned a title, which the developer may choose to show or not. In the column, the CellRenderer widgets are added.

===========
Constructor
===========
The TreeViewColumn construction method is::

  GtkWidget *treeviewcolumn = gtk_tree_view_column_new();

=======
Methods
=======
The TreeViewColumn can hold one or more CellRenderer widgets, and are placed either at the left edge of the cell, or the right edge of the cell depending on the method defined::

  gtk_tree_view_column_pack_start(GTK_TREE_VIEW_COLUMN(treeviewcolumn), cellrenderer, expand);
  gtk_tree_view_column_pack_end(GTK_TREE_VIEW_COLUMN(treeviewcolumn), cellrenderer, expand);

The *cellrenderer* property indicates the CellRenderer to be added to the column. The *expand* property when set to ``TRUE`` expands the contents to the width of the column.

A column can be cleared of any CellRenderer widgets held via::

  gtk_tree_view_column_clear(GTK_TREE_VIEW_COLUMN(treeviewcolumn));

A title can be defined on the TreeViewColumn with::

  gtk_tree_view_column_set_title(GTK_TREE_VIEW_COLUMN(treeviewcolumn), title);

Rather than a simple string being provided, a widget, such as a :doc:`label` can be used as the title instead via::

  gtk_tree_view_column_set_widget(GTK_TREE_VIEW_COLUMN(treeviewcolumn), widget);

By default, each column is sized to the content. They can be expanded however to fill the space provided by the TreeView by calling::

  gtk_tree_view_column_set_expand(GTK_TREE_VIEW_COLUMN(treeviewcolumn, expand);

A minimum and maximum width can also be specified with::

  gtk_tree_view_column_set_min_width(GTK_TREE_VIEW_COLUMN(treeviewcolumn), min_width);
  gtk_tree_view_column_set_max_width(GTK_TREE_VIEW_COLUMN(treeviewcolumn), max_width);

A fixed width defined in pixels can be set by using::

  gtk_tree_view_column_set_fixed_width(GTK_TREE_VIEW_COLUMN(treeviewcolumn), fixed_width);

Sizing modes can also be configured to adjust how the column behaves when the content changes. These are set with the call::

  gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN(treeviewcolumn), sizing);

The *sizing* parameter should be set to one of the constants:

* ``GTK_TREE_VIEW_COLUMN_GROW_ONLY`` - only allow columns to increase in width.
* ``GTK_TREE_VIEW_COLUMN_AUTOSIZE`` - columns resize to the optimal size.
* ``GTK_TREE_VIEW_COLUMN_FIXED`` - a fixed pixel width is defined.

Resizability of a column by the user can be toggled with::

  gtk_tree_view_column_set_resizable(GTK_TREE_VIEW_COLUMN(treeviewcolumn), resizable);

The visibility of a column can be toggled by calling::

  gtk_tree_view_column_set_visible(GTK_TREE_VIEW_COLUMN(treeviewcolumn), visible);

Retrieval of a column visibility state can be done by::

  gtk_tree_view_column_get_visible(GTK_TREE_VIEW_COLUMN(treeviewcolumn));

A TreeViewColumn can be used to fetch the attached TreeView::

  gtk_tree_view_column_get_tree_view(GTK_TREE_VIEW_COLUMN(treeviewcolumn));

If the TreeViewColumn is not attached to a TreeView, ``NULL`` is returned by the method.

When a column contains more than one cell, the spacing between the cells may need to be defined to ensure a tidy appearance. This is settable using::

  gtk_tree_view_column_set_spacing(GTK_TREE_VIEW_COLUMN(treeviewcolumn), spacing);

The *spacing* value should be defined as an integer number in pixels.

=======
Example
=======
For an example of the TreeViewColumn, see the :doc:`liststore` or :doc:`treestore` examples.
