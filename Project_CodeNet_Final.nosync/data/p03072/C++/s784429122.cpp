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
	ll n;cin>>n;
	ll a[n];rep(i,0,n)cin>>a[i];
	ll c=0;
	rep(i,0,n){
		bool f=0;
		rep(j,0,i)if(a[j]>a[i])f=1;
		if(!f)c++;
	}cout<<c;
	return 0;
}

