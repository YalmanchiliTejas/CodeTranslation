#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;


int modpow(int a, int n) {
	int r = 1;
	while (n) {
		r = r * ((n % 2) ? a : 1) % mod;
		a = a * a%mod, n >>= 1;
	}
	return r;
}

int comb(int P, int Q) {
	if (P < 0 || Q<0 || Q>P)return 0;
	int p = 1, q = 1;
	Q = min(Q, P - Q);
	eFOR(i, 1, Q) {
		p = p * P%mod;
		q = q * i%mod;
		P--;
	}
	return p * modpow(q, mod - 2) % mod;
}

signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	
	int ret = 0;
	REP(i, N) {
		int d = 1LL * i*(i + 1) / 2 % mod;
		d = d * M%mod*M%mod;
		ret += d;
	}
	REP(i, M) {
		int d = 1LL * i*(i + 1) / 2 % mod;
		d = d * N%mod*N%mod;
		ret += d;
	}

	cout << ret % mod*comb(N*M - 2, K - 2) % mod << endl;
	
	return 0;
}

