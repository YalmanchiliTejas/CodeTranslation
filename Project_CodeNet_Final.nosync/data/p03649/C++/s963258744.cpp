#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  
  int N; cin >> N;
  
  vector<ll> a(N); ll S = 0;
  vector<ll> r(N); vector<ll> e(N);
  
  ll ans = 0;
  
  for(int i = 0; i < N; i++){ cin >> a[i];}
  
 while(true){
  
  bool flag = true;
    
    ll res = 0;
  
  for(int i = 0; i < N; i++){
   
    res = max(res, a[i]/N); //最大値が0になるまで続行
   
  }
 
    
    if(res < 1){ break;} //この時終了
    
  ll R = 0;
    
    for(int i = 0; i < N; i++){ 
    r[i] = a[i]/N;
    e[i] = a[i]%N;
    R += r[i];
   
  }
    
    ans += R;
    
    for(int i = 0; i < N; i++){ 
      a[i] = R-r[i]+e[i];
    }
  
  }
  
  cout << ans << endl; return 0;
}
  
    