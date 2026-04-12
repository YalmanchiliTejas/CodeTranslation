#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<queue>

#define mp(a,b) make_pair(a,b)

using namespace std;
int main(){
  int n;
  while(cin >> n && n != 0){
    int x = 0;
    int mx = -1,mn = 1000;
    for (int i = 0; i < n; ++i){
      int tmp;
      cin >> tmp;
      x += tmp;
      mx = max(tmp,mx);
      mn = min(tmp,mn);
    }
    x -= mn;
    x -= mx;
    x /= n-2;
    cout << x << endl;
  }
  return 0;
}