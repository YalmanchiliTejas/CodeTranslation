#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define F first
#define S second
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sortv(X) sort(X.begin() , X.end()) ; 
#define ll long long 
#define ld long double
#define pii pair <int ,int >
#define bug(x)  cout<<"passed "<<x<<endl;
#define ashar(x , y , z) cout<<setprecision(x)<<fixed<<y ; if (z==1) cout<<"\n" ;
#define ppi pair <pair <int, int > , int > 
#define ordered_set tree<pair <long long  ,long long >, null_type,less<pair <long long ,long long > >, rb_tree_tag,tree_order_statistics_node_update> 
  
long long const inf = 3e18, linf = 2e9, mod = 1e9+7 , inf2 = 1e12;
int const mxn = 5e5 + 10 ;
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}



long long sumk , ans , A[mxn] ; 
int main(){
	int n ; 
	cin>>n ; 
	for (int i = 1 ; i <= n ; i++){
		cin>>A[i] ;
		sumk+=A[i] ;  
		sumk%=mod ; 
	}
	for (int i = 1 ; i <= n ; i++){
		sumk-=A[i] ; 
		sumk = (sumk+mod)%mod ; 
		ans += (A[i]*(sumk))%mod ; 
		ans%=mod ; 
	}
	cout<<ans ; 
}
