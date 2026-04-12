//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
	



int main(){
   IOS

   int n; cin>>n;
   vi a(n);
   for(int &x : a)cin>>x;

   ll s1 = 0, s2 = 0;

   for(int i = 0; i < n; i++){
	   s1 += a[i];
	   if(s1 >= mod)s1 -= mod;
	   s2 += (ll)a[i] * a[i] % mod;
	   if(s2 >= mod)s2 -= mod;
   }

	s1 = s1 * s1 % mod;
	
	ll ans = (s1 - s2 + mod) % mod;
	ans = ((ans % mod) * (pwr(2, mod - 2) % mod)) % mod;

	cout<<ans<<'\n';


	







}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
	if(b&1) res = res * a % mod;
		a = a * a % mod;
	b >>= 1;
	}

	return res;
}

