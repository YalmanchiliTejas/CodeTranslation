#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

vector<ll> a;

bool solve(ll m){
  ll num = 0;
  ll N = a.size();
  for(auto &&x : a){
    ll nokori = x+m-(N-1);
    num += max((ll)0, (nokori+N)  / (N+1));
  }
  return num <= m;
}

int main(){
  ll N;
  cin >> N;
  a.resize(N);
  bool ok = true;
  ll sum = 0;
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum+=a[i];
    if(a[i]>=N)
      ok=false;
  }
  ll zatu = max((ll)0, sum -N*N);
  ll rest = zatu;
  ll ans = 0;
  for(int i=0;i<a.size();i++){
    ll nokori = a[i]+zatu-(N-1);
    ll num = min(rest, max((ll)0, (nokori+N)  / (N+1)));
    rest -= num;
    a[i] = a[i] + zatu - (N+1) * num;
    ans += num;
  }
  for(ll plus = 0;true;plus++){
    if(solve(plus)){
      ans += plus;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
