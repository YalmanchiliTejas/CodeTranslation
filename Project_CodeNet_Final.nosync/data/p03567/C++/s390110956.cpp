#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define scd second
#define all(x) x.begin(), x.end()
#define N int(1e6+10)
#define mkp make_pair

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef list<int> li;
typedef list<ll> llong;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;

ll gcd(ll a, ll b){
	return (b==0 ? a : gcd(b,a%b));
}

ll lcm(ll a, ll b){
	ll g=gcd(a,b);
	return (a/g)*b;
}

ll inv_mod(ll a, ll b){
	ll x=0, y=1, r, q, ta=a;
	while(b){
		q=a/b;
		r=a%b;
		a=b;
		b=r;
		r=x;
		x=y;
		y=r-q*y;
	}
	x+=ta;
	return x%ta;
}

int main(){
	string s;
	cin>>s;
	for(int i=1; i<s.length(); i++){
		if(s[i]=='C' && s[i-1]=='A'){
			cout<<"Yes\n";
			return 0;
		}
	}

	cout<<"No\n";
}