/*-- ILSH  --*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < ll > 
#define pii pair< ll, ll > 
#define len length 
#define fi first
#define se second
#define dt cout<<"HEre\n";
#define sz size
const ll inf=1e18+1e17;
const ll mod = 1e9+7;


ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}
const ll N = ( 1<<18);
void solve() {
	int n;
	cin>>n;
	if ( n> 29 ) 
		cout<<"Yes\n";
	else
		cout<<"No\n";



}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen ("INPUT.txt" , "r" , stdin);
		freopen ("OUTPUT.txt", "w" , stdout);
	#endif
	ll t=1;
//	cin>>t;
	for ( ll i=1;i<=t;i++){
	//	cout<<"Case #"<<i<<": ";
    	solve();
    }
    //	cout << clock() / double(CLOCKS_PER_SEC) << endl;
}