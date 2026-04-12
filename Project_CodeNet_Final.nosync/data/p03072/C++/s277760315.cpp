#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cstring>
using namespace std;
long long int mod = 1e9 + 7;
int inf = 1e9;

int main() {
  int n; cin >> n;
  int cnt = 0;
  int h = 0;
  for(int i=0; i<n; i++) {
    int a; cin >> a;
    if(a >= h) cnt++;
    h = max(a, h);
  }
  cout << cnt << endl;

  return 0;
}


//EOF
