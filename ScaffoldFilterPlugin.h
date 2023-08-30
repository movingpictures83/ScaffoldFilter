#ifndef SCAFFOLDFILTERPLUGIN_H
#define SCAFFOLDFILTERPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class ScaffoldFilterPlugin : public Plugin
{
public: 
 std::string toString() {return "ScaffoldFilter";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
