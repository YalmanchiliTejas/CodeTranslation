#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<pair<ll, ll>, bool> DP;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007, inv2=(mod+1)/2;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

DP Get(DP p, int ted){
	p.first.first=p.first.first*powmod(2, ted)%mod;
	return p;
}

DP Merge(DP p, DP q){
	if (!p.second) return q;
	if (!q.second) return p;
	ll dp=(p.first.first*q.first.first)%mod*inv2%mod;
	return {{dp, ((p.first.first+p.first.second)*(q.first.first+q.first.second)-dp)%mod}, 1};
}

DP Solve(int tl, int tr, int h){
//	cerr<<"Solve "<<tl<<" "<<tr<<" "<<h<<"\n";
	if (tl>tr) return {{0, 0}, 0};
	if (tl==tr) return Get({{2, 0}, 1}, A[tl]-1-h);
	ll mn=inf, pos;
	for (int i=tl; i<=tr; i++) if (A[i]<mn) mn=A[i], pos=i;
	int last=tl;
	DP res={{0, 0}, 0};
	for (int i=tl; i<=tr; i++) if (A[i]==mn){
		res=Merge(res, Solve(last, i-1, mn-1));
		res=Merge(res, {{2, 0}, 1});
		last=i+1;
	}
	if (last<=tr) res=Merge(res, Solve(last, tr, mn-1));
	res=Get(res, mn-1-h);
	
//	cerr<<"Solve "<<tl<<" "<<tr<<" "<<h<<":  "<<res.first.first<<" "<<res.first.second<<"\n";
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	DP res=Solve(1, n, 0);
	ans=(res.first.first+res.first.second+2ll*mod)%mod;
	cout<<ans<<"\n";
	
	return 0;
}
