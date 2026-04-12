#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i, s, n) for(int i=s; i<n; i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {
  int X;
  cin >> X;
  if(X==7 || X==5 || X==3) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
