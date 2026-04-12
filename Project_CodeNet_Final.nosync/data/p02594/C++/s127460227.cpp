#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fo(i,n) for(ll i=0;i<n;i++)
#define fo1(i,n) for(ll i=1;i<=n;i++)
#define loop(i,a,b)for(ll i=a;i<=b;i++)
#define loopr(i,a,b)for(ll i=b;i>=a;i--)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define vll vector<ll>
#define vvl vector<vll>
#define pll pair<ll,ll>
#define F first
#define S second
#define MOD 1000000007
ll max(ll a,ll b){if (a>b) return a; else return b;}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll fexp(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%MOD; b/=2;a=a*a%MOD;}return ans;}
ll inverse(ll a, ll p){return fexp(a, p-2);}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
//	cin >> T;
	ll t=0;
	while(t++<T){
    ll X;
    cin >> X;
    if(X>=30) cout << "Yes" << endl;
    else cout << "No" << endl;
	}
return 0;
}
