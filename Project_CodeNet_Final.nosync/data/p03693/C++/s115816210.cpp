#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <numeric>
 
#include <stdio.h>
#include <string.h>
 
using namespace std;
  
int main(int argc, char* argv[])
{
 
	int r,g,b;

	cin >> r >> g >> b;

	cout << ((r*100+g*10+b) % 4 ==0 ? "YES" : "NO") << endl;
 
	return 0;
 
}