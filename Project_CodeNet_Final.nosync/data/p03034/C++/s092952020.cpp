#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int const MAXN=110000;
int N;
int S[MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	cin>>N;
	rep(i,0,N) cin>>S[i];
	
	ll res=0;
	for (int d=1; d*d<=N; ++d) {
		vector<vector<ll>> sums(d);
		rep(i,0,N) {
			ll v=S[i];
			if (!sums[i%d].empty()) v+=sums[i%d].back();
			sums[i%d].push_back(v);
		}
		
		rep(A,1,N-1) if ((N-1-A)%d==0) {
			int k=(N-1-A)/d;		
			if (A<=d || (A%d==0 && k>=A/d)) continue;
			ll sum=sums[0][k];
			sum+=sums[A%d][A/d+k];
			if (A/d>0) sum-=sums[A%d][A/d-1];
			res=max(res,sum);
		}
	}
		
	cout<<res<<"\n";
}
