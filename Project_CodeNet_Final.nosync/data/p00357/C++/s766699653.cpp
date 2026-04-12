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
  int n;
  cin >> n;
  int d[n];
  FOR(i,0,n) cin >> d[i];
  int p = d[0];
  bool yes = true;
  FOR(i,1,n){
    p -= 10;
    if(p < 0) yes = false;
    p = max(p, d[i]);
  }
  p = d[n-1];
  for(int i = n - 2; i >= 0; i--){
    p -= 10;
    if(p < 0) yes = false;
    p = max(p, d[i]);
  }
  cout << (yes ? "yes" : "no") << endl;
}
