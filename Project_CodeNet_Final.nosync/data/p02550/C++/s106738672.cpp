//https://atcoder.jp/contests/abc179/tasks/abc179_e

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  ll n, x, m;
  cin >> n >> x >> m;
  vector<int> id(m, -1);
  vector<int> a;
  int len = 0;
  ll tot = 0;
  while(id[x]==-1){
    a.push_back(x);
    id[x]=len;
    len++;
    tot += x;
    x=(x*x)%m;
  }
  int c = len-id[x];//周期
  ll s = 0;//周期の1ループ分の和
  for(int i=id[x];i<len;++i)s+=a[i];
  ll ans = 0;
  //2周目にくるまでよりも短い場合
  if(n<=len){
    rep(i, n)ans+=a[i];
  }else{
    ans += tot;
    n -= len;
    ans += s*(n/c);
    n%=c;
    rep(i, n)ans += a[id[x]+i];
  }

  cout << ans << endl;
  return 0;
}
