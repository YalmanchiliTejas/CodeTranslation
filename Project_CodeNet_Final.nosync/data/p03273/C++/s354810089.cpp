#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w;
  cin >> h >> w;
  vector<string> vs(h);
  FOR(i,0,h) cin >> vs[i];
  FOR(i,0,h) {
    bool del = true;
    FOR(j,0,w) {
      if(vs[i][j] == '#') del = false;
    }
    if(del) {
      FOR(j,0,w) vs[i][j] = 'X';
    }
  }
  FOR(j,0,w) {
    bool del = true;
    FOR(i,0,h) {
      if(vs[i][j] == '#') del = false;
    }
    if(del) {
      FOR(i,0,h) vs[i][j] = 'X';
    }
  }
  FOR(i,0,h) {
    FOR(j,0,w) {
    	if(vs[i][j] != 'X') {
          cout << vs[i][j];
        }
    }
    cout << endl;
  }
}
