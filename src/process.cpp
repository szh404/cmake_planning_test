#include "process.h"
#include <iostream>
using namespace std;

void Process::planProcess()
{
    cout << "this is planning process" << endl;
    my_map.mapInfo();
    cout << "planning success!" << endl;
};