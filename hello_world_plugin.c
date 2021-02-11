/* 
    A simple Hello world plugin that works with 
    the GCC static analyzer during a Kernel build.
*/

#include "gcc-common.h"

__visible int plugin_is_GPL_compatible;

static struct plugin_info hello_world_analyzer_plugin_info = {
  .version  = "20210207",
  .help   = "A simple Hello-World gcc-analyzer-plugin that runs during a kernel build\n",
};

static void hello_world_analyzer_callback (void *gcc_data, void *user_data)
{
    fprintf(stderr, "-----\nHello, from the plugin callback!\n-----\n");
}

__visible int plugin_init (struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
  if (!plugin_default_version_check(version, &gcc_version)) {
    error(G_("Incompatible GCC/Plugin versions!"));
    return 1;
  }
  const char *plugin_name = plugin_info->base_name;
    fprintf(stderr, "Hello-World plugin registered!\n");
  register_callback (plugin_name,
         PLUGIN_ANALYZER_INIT,
         hello_world_analyzer_callback,
         NULL);

  return 0;
}
