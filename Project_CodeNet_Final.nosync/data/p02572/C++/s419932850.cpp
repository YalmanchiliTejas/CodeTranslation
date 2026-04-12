#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define N 500005
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int32_t main(){
	IOS;
	int tt = 1; 
	//cin >> tt;
  const int mod = 1e9 + 7;
	while(tt--){
    int n; cin >> n;
    int A[n];
    int pre[n + 1] = {};
    for(int i = 0; i < n; i++){
      cin >> A[i];
      pre[i + 1] += pre[i] + A[i];
    }
    int ans = 0;
    
    for(int i = 0; i < n; i++){
      ans += (pre[i] % mod * A[i] % mod) % mod;
      ans %= mod;
    }
    cout << ans << endl;
	}
	return 0;
}
