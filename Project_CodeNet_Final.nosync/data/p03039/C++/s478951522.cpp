#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define Mod 1000000007
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair
#define big_prime 15486277
#define bigger_prime 179424697
#define biggest_prime 32416188691
//#define random_shuffle(indices.begin(), indices.end());
//std::random_device rd;
//std::mt19937 g(rd());
//std::shuffle(v.begin(), v.end(), g);
using namespace __gnu_pbds; 
using namespace std;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

#define MAX 300000


ll fact[MAX];
ll power(ll a,ll b){
	if(b==0) return 1;
	ll temp = power(a,b/2)%Mod;
	if(b%2==0){
		return (temp*temp)%Mod;
	}else{
		return (a*((temp*temp)%Mod))%Mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fact[0]=1;
	For(i,1,MAX) fact[i]=(fact[i-1]*i)%Mod;
	ll n,m,k;cin>>n>>m>>k;

	ll ans=0;
	ll z = ((fact[n*m-2])*power((fact[n*m-2-(k-2)]*fact[k-2])%Mod,Mod-2))%Mod;

	vector<ll> X,Y;
	For(i,0,n) For(j,0,m) {
		X.pb(i+1);
		Y.pb(j+1);
	}	
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	ll p1 = 0 , p2=0;
	For(i,0,X.size()){
		ll t1 = (X[i]*i)%Mod;
		ll t2 = (Y[i]*i)%Mod;
		ans+=(t1-p1+Mod);
		ans%=Mod;
		ans+=(t2-p2+Mod);
		ans%=Mod;
		p1+=X[i];
		p1%=Mod;
		p2+=Y[i];
		p2%=Mod;
	}

	cout<<(ans*z)%Mod<<endl;
	











	
}