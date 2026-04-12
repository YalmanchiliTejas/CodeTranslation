#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
template <class Q>
void clearQueue(Q & q) {
    q = Q();
}
void solve(){
    int n;cin>>n;
    int tot=0;
    vector<int>v(n);
 
  for(int i=0;i<n;i++){
    cin>>v[i];
    tot+= v[i];
  }
  int ans =0;
  for(int i=0;i<n;i++){
     tot-=v[i];
     ans = (ans%MOD + (tot %MOD *v[i] % MOD) %MOD)%MOD;
  }
  cout<<ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
