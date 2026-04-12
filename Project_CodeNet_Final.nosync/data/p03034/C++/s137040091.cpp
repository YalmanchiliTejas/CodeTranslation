#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	int N;
	cin>>N;
	vector<int> S(N);
	rep(i,0,N) cin>>S[i];
	
	ll res=0;
	rep(d,1,N-1) {
		ll sum=0;
		set<int> was;
		for (int k=1; k*d<N-1; k++) {
			sum+=S[k*d]+S[N-1-k*d];
			if (was.count(k*d)) break;
			was.insert(k*d);
			if (was.count(N-1-k*d)) break;
			was.insert(N-1-k*d);
			
			int A=N-1-k*d;
			int B=A-d;
			if (B>0 && A>=B) res=max(res,sum);
		}
	}

	cout<<res<<"\n";
}
