/*
     _              ,_,
    / \   _ __, ___,| |__   __ _,_ __
   / ^ \ | '_ \/ _ \| '_ \ / _` | /_/
  /-/-\-\|-| |--| |-|-|_)-|-(_|-|-|
 /_/   \_\_| |__| |_|_.__/ \__,_|_|
 
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(a)       (a).begin(),(a).end()
#define rep(i,a,n)   for(int i=a ; i<n ; i++)
 
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<ll,ll> mii;
typedef map<char,ll> mci;
 
ll gcd(ll a, ll b){
	if(b==0)return a;
	else return gcd(b, a%b);
}

signed main(){
    ios_base :: sync_with_stdio (false);
	cin.tie(NULL);
	// cout << fixed << setprecision(15);
 
	ll TESTS=1; 
	// cin>>TESTS;
	while(TESTS--){
		ll x; cin>>x;
		if(x>=30)cout<<"Yes";
		else cout<<"No";
		cout<<endl;


	}
    return(0);
}