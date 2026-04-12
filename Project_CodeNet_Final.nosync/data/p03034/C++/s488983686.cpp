#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[200005];
vector<ll>beg[200005],ruib[200005];
vector<ll>en[200005],ruie[200005];
int main(){
	cin>>n;
	rep(i,n) cin>>a[i];
	for(int i=1;i<=n-1;i++){
		for(int j=0;j<n;j+=i){
			beg[i].pb(a[j]);
			if(ruib[i].empty()) ruib[i].pb(a[j]);
			else ruib[i].pb(ruib[i][ruib[i].size()-1]+a[j]);
		}
		for(int j=n-1;j>=0;j-=i){
			en[i].pb(a[j]);
			if(ruie[i].empty()) ruie[i].pb(a[j]);
			else ruie[i].pb(ruie[i][ruie[i].size()-1]+a[j]);
		}
	}
	
	ll ans = 0;
	for(ll p=2;p<n;p++){
		for(ll d=1;d<=(n-1)/(p-1);d++){
			ll A = n-1-d*(p-1);
			if(A<=d) continue;
			ll B = A-d;
			if(A%(A-B) == 0 && A/(A-B)<=p-1) continue;
			ans = max(ans,ruib[d][p-1]+ruie[d][p-1]);
			//cout<<A<<B<<p<<endl;
		}}
		cout<<ans<<endl;
	}