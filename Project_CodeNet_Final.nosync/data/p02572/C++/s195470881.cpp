#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vs vector<string>
#define pb push_back
#define rep(i,n) for(int i = 0;i<n;i++)
#define repk(k,n) for(int i = k;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto n:v){cout << n << "\t";}
#define input(v) for(auto &i:v){cin >> i;}
#define mod 1000000007
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vll v(n);
	ll sum = 0;
	for(int i =0;i<n;i++){
		cin >> v[i];
		sum+=v[i];
		sum%=mod;
	}
	vll add(n+1,0);
	for(int i = n-1;i>=0;i--){
		add[i]+=v[i]+add[i+1];
		add[i]%=mod;
	}
	ll result = 0;
	for(int i =0;i<n-1;i++){
		ll k = v[i]*add[i+1];
		k%=mod;
		result+=k;
		result%=mod;
		
	}
	cout << result << endl;
	

}


int main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}

	return 0;
}