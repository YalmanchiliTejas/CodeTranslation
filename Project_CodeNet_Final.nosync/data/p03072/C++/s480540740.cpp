#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF 1000000007
#define PI acos(-1.0)
#define endl "\n"
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP_R(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define FOR(i,m,n) for(int i=((int)(m));i<(int)(n);++i)
#define FOR_R(i,m,n) for(int i=((int)(m)-1);i>=(int)(n);--i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZ(x) ((int)(x).size())
typedef long long int lli;
using namespace std;

int main()
{
  int N;

  cin >> N;

  vector<int> H(N);

  REP(i,N)
    {
      cin >> H[i];
      
    }

  int mx = H[0];

  int cnt = 1;

  FOR(i,1,N)
    {
      
      if( mx <= H[i] )
	{
	  ++ cnt;

	  mx = H[i];
	  
	}

      
    }

  cout << cnt << endl;
  
  

}
