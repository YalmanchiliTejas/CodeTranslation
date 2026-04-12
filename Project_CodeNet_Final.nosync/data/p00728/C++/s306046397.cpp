#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(1) {
		ll n;
		cin>>n;
		if(n==0) break;
		vector<ll> s(n);
		REP(i,n) cin>>s[i];
		sort(ALL(s));
		ll sum=accumulate(ALL(s),0);
		sum-=s[0]+s[n-1];
		cout<<sum/(n-2)<<endl;
	}
}

