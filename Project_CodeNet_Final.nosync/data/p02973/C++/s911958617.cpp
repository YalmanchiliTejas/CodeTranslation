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
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define M 1000010

int main(){
	IOS;
	ll n;cin>>n;
	ll a[n+1];rep(i,1,n+1)cin>>a[i];
	multiset<ll>s;
	rep(i,1,n+1){
		auto it=s.lower_bound(a[i]);
		if(it!=s.begin()){
			it--,s.erase(it);
		}
		s.insert(a[i]);
	}
	cout<<sz(s);
	
	return 0;
}

