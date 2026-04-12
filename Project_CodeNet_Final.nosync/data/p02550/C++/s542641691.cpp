#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n,x,m;
  cin >> n >> x >> m;
  long ai = x;
  long ans = 0;
  long rui[m+1];
  vector<vector<long>> flag(m+1);
  rep(i,m+1)rui[i] = 0;
  // rui[0] = ai;
  rui[0] = 0;
  long suma = INF,num = INF, t = 0;
  int f = 0;
  for(long i=1;i<=min(m,n);i++){
    rui[i] = rui[i-1] + ai;
    if(int(flag[ai].size())){
      suma = rui[i] - flag[ai][1];
      num = i - flag[ai][0];
      t = i;
      f = 1;
      break;
    }
    ans += ai;
    flag[ai].push_back(i);
    flag[ai].push_back(rui[i]);
    ai *= ai;
    ai %= m;
  }
  if(f)ans += ((n-t+1)/num) * suma;
  if(f){
    for(long i=0;i<(n-t+1)%num;i++){
    ans += ai;
    ai *= ai;
    ai %= m;
    }
  }
  cout << ans << endl;
  return 0;
}