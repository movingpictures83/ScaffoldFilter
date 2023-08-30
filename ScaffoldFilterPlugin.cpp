#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ScaffoldFilterPlugin.h"

void ScaffoldFilterPlugin::input(std::string file) {
 inputfile = file;
}

void ScaffoldFilterPlugin::run() {}

void ScaffoldFilterPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand +=  "awk -F\"\\t\" \'{obj1[$1]+=$3;++obj2[$1]}END{for (key in obj1) print key\"\\011\"obj1[key]/obj2[key]}\' "+inputfile+" | sort -nr -k2,2 > "+file;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<ScaffoldFilterPlugin> ScaffoldFilterPluginProxy = PluginProxy<ScaffoldFilterPlugin>("ScaffoldFilter", PluginManager::getInstance());

