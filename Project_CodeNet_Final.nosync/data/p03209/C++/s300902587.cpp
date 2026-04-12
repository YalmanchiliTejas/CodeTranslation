// D

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

int main(){
  int N;
  ll x;
  cin>>N>>x;
  ll L[51] = {0};
  L[0] = 1;
  ll p[51] = {0};
  p[0] = 1;
  for (int i(1);i<N;i++){
    L[i] = 2 * L[i-1] + 3;
    p[i] = 2 * p[i-1] + 1;
  }
  for (int i(0);i<N;i++){
    //cout << L[i] << " " << p[i] << endl;
  }
  ll now(0);
  ll ans(0);
  int v(1);
  for (int i(N-1);i>=0;i--){
      now += v*(L[i] + 2);
      ans += v*(p[i] + 1); 
    if (now == x){
      cout << ans << endl;
      return 0;
    }else if (now < x){
      v = 1;
    }else{
      v = -1;
    }
  //  cout << now << " "<<ans << endl;
  }
  if (now - x <= 2 && now - x > 0){
    cout << ans - (now - x) << endl;
  }else if(now - x == 3){
    cout << ans - 2 << endl;
  }else if (now - x < 0){
    cout << ans + 1 << endl;
  }
}

