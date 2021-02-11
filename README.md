# Hello world plugin

This is a simple Hello world plugin that works with the Static Analyzer in GCC (>=11)
and can be used while building the Linux Kernel.

Copy the plugin file to `scripts/gcc-plugins`. 

Then make the necessary changes to `scripts/gcc-plugins/Kconfig` and `scripts/Makefile.gcc-plugins` to include this plugin in the list of plugins.

After this, when you build the kernel, specify the path for the version of GCC with analyzer support (>=11) if it's not 
the default installation, and include the option `-fanalyzer`.

You should be able to see `Hello, from the plugin callback!` for every file compiled if you've enabled the analyzer option.
