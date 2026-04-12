//=template==================================================================//
// include
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

// namespace
using namespace std;

// define
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(i,n) FOR(i,0,n)

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long LL;

// conversion
inline int toInt(string s) {int v; istringstream sin(s); sin>>v; return v;}
template<class T> inline string toString(T x) {ostringstream sout; sout<<x; return sout.str();}
//===========================================================================//

//=function prototype========================================================//

//===========================================================================//

//=variables=================================================================//
long X, Y, Z;
//===========================================================================//
int main(void)
{
  // Scan begin.
  scanf("%ld %ld %ld", &X, &Y, &Z);
  // Scan done.

  // Code begin.
  printf("%ld\n", (X-Z)/(Y+Z));
  // Code done.

  // return begin.
  return 0;
  // return done.
}

//=functions=================================================================//

//===========================================================================//