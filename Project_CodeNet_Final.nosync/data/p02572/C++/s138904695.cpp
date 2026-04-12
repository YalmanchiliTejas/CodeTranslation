/*
    If they say
    Who cares if one more light goes out?
    In a sky of a million stars
    It flickers, flickers
    Who cares when someone's time runs out?
    If a moment is all we are
    We're quicker, quicker
    Who cares if one more light goes out?
    Well I do
*/

#include<bits/stdc++.h>
using namespace std;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a) / gcd(a,b)) * (b)
#define all(x)  x.begin(),x.end()

#define ll long long
#define ull unsigned long long
#define VI vector<int>
#define VLL vector<ll>
#define VS vector<string>
#define MPII map<int, int>
#define SET set<int>
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define fast_io   ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);

ll MOD = 1e9+7;

ll add(ll a, ll b)
{
	a+=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	if(a>MOD) a%=MOD;
	if(b>MOD) b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
ll pw(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    ll arr[n];
    ll sm[n];
    ll sum=0;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        sum = add(sum, arr[i]);
        sm[i] = sum;
    }
    for(int  i = 0 ;  i < n ; i++){
        ans=add(ans, mult(sm[n-1]-sm[i],arr[i]));
        ans %= MOD;
    }
    ans %= MOD;
    cout<<ans<<endl;
}

int main(){
    fast_io;
    ll t, k=0;
    t=1;
    while(t--){
        //k++;
        //cout<<"Case "<<k<<": ";
        solve();
    }
}

