#include "ProcessParser.h"

#include "util.h"

std::string ProcessParser::getCmd(std::string pid) {
  std::string cmd_path = Path::basePath() + "/" + pid + "/" + Path::cmdPath();
  std::ifstream cmdline = Util::getStream(cmd_path);
  std::string cmd_name;
  getline(cmdline, cmd_name);
  return cmd_name;
}

std::vector<std::string> ProcessParser::getPidList() {
  DIR* dir;
  struct dirent* entry;
  std::vector<std::string> pidList;
  if ((dir = opendir(Path::basePath().c_str())) != NULL) {
    while ((entry = readdir(dir)) != NULL) {
      if (entry->d_type =
              DT_DIR && Util::isPidDir((std::string)entry->d_name)) {
        pidList.push_back((std::string)entry->d_name);
      }
    }
    return pidList;
  } else {
    throw std::runtime_error("Directory cannot be opened");
  }
}

std::string ProcessParser::getVmSize(std::string pid) {
  string line;
  string name = "VmData";
  float vm_usage;
  std::ifstream stream =
      Util::getStream(Path::basePath() + pid + Path::statusPath());

  while (getline(stream, line)) {
    if (line.compare(0, name.size(), name) == 0) {
      return line;
    }
  }
}

int main() {
  std::cout << ProcessParser::getCmd("1543") << "\n";
  for (auto const& pid : ProcessParser::getPidList()) {
    std::cout << pid << "\n";
  }
  std::cout << ProcessParser::getVmSize("1543") << "\n";
}