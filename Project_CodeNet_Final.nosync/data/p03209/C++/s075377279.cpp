#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

ll size[51];
ll p[51];

ll dfs(ll level,ll num){
  if(num == 0)return 0;
  else if(num == size[level])return p[level];
  else if(num >= size[level-1] + 2){
    return dfs(level-1,num-size[level-1] - 2) + p[level-1] + 1;
  }
  else if(num >= 1){
    return dfs(level-1,num-1);
  }
}

int main(){
  size[0] = 1;
  p[0] = 1;
  for(int i = 1;i <= 50;i++){
    size[i] = size[i-1] * 2 + 3;
    p[i] = p[i-1] * 2 + 1;
  }

  ll n,x;
  cin >> n >> x;

  ll ans = dfs(n,x);

  cout << ans << endl;
}