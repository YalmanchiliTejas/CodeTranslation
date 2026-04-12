#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define inf 1e16
#define M 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define mx 1000010

int main(){
	IOS;
	ll n,k;
	string s;cin>>n>>s>>k;
	char c;
	rep(i,0,n)if(i+1==k)c=s[i];//cout<<c<<" ";
	rep(i,0,n){
		if(s[i]==c)cout<<s[i];
		else cout<<"*";
	}
	return 0;
}

