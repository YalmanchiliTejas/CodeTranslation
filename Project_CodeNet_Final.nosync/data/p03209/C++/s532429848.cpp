#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n; i++)
#define all(a) (a).begin(),(a).end()

LL t[60], p[60];
LL ans;

void rec(LL now, LL rem){
  if(now == 0){
    ans++;
    return;
  }
  if(--rem <= 0) return;
  if(rem < t[now-1]){
    rec(now-1, rem);
  }else{
    rem -= t[now-1];
    ans += p[now-1];
    if(rem == 0) return;
    rem--; ans++;
    if(rem == 0) return;
    if(rem < t[now-1]){
      rec(now-1, rem);
    }else{
      rem -= t[now-1];
      ans += p[now-1];
      assert(rem <= 1);
    }
  }
}

int main(){
  LL n, x;
  cin >> n >> x;
  t[0] = 1;
  p[0] = 1;
  rep(i, n){
    t[i+1] = 2*t[i]+3;
    p[i+1] = 2*p[i]+1;
  }
  rec(n, x);
  cout << ans << endl;
}
