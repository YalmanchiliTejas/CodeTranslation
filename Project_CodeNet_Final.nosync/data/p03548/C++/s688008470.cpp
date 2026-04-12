#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(var,start,end) for(int var=start; var<end; var++)
#define REP(var,cnt) FOR(var,0,cnt)

int main(void) {
	
	int X, Y, Z;
	cin >> X >> Y >> Z;
	
	if ( X < (Y+Z+Z) ) { cout << "0" << endl; return 0; }
	
	X -= Z;
	int kos = X / (Y+Z);
	
	cout << kos << endl;
}
