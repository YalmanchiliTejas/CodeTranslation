#include <tuple>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using ll	= long long;
using ull	= unsigned long long;
using ld	= long double;
using pii	= pair<int,int>;
using pll	= pair<ll,ll>;
using vi	= vector<int>;
using vb	= vector<bool>;
using vc	= vector<char>;
using vvi	= vector<vi>;
using vvb	= vector<vb>;
using vpii	= vector<pii>;
using vpll	= vector<pll>;
using vll	= vector<ll>;
using vull	= vector<ull>;
using vvll	= vector<vll>;
#define ever (;;)
#define f first
#define s second
#define pb emplace_back
#define sz size()
#define graph vector<vertex>
#define deg(X) (int)G[X].e.size()
#define INF 1234567890
#define INFll 2000000000000000000
#define maxe(X, Y) if((Y) > (X)) (X) = (Y)
#define mine(X, Y) if((Y) < (X)) (X) = (Y)
#define rep(i, begin, end) for(__typeof(end) i = (begin); i < (end); ++i)
#define repr(i, begin, end) for(__typeof(end) i = (begin)-1; i >= (end); --i)
#define bend(X) X.begin(), X.end()
pii operator+(const pii& A, const pii& B) { return {A.f+B.f, A.s+B.s}; }
pii operator-(const pii& A, const pii& B) { return {A.f-B.f, A.s-B.s}; }
pii operator-(const pii& A) { return {-A.f, -A.s}; }

//
// END OF DEFINES
//

int n;
vll T;
vvll DP;
vll P;

bool in() {
	scanf("%d", &n);
	T.resize(n);
	P.resize(n+1);
	DP.resize(n, vll(n));
	rep(i, 0, n)
		scanf("%lld", &T[i]);
	
	return true;
}

ll get(int a, int b) {
	return P[b+1]-P[a];
}

ll solve() {
	rep(i, 1, n+1)
		P[i] = P[i-1] + T[i-1];
	
	rep(i, 0, n)
		DP[i][i] = T[i];
	rep(l, 1, n) {
		rep(i, 0, n-l) {
			int j = i+l;
			DP[i][j] = get(i, j) - min(DP[i+1][j], DP[i][j-1]);
		}
	}
	
	ll X = DP[0][n-1];
	ll Y = get(0, n-1)-X;
	return X-Y;
	
	return -INF;
}

int main() {
	int noOfTests = 1;
	//scanf("%d", &noOfTests);
	
	while(noOfTests --> 0) {
		if(!in()) {
			printf("popsute wejscie\n");
			continue;
		}
		ll result = solve();
		if(result == ll(-'t'))
			printf("TAK\n");
		else if(result == ll(-'n'))
			printf("NIE\n");
		else if(result != -INF)
			printf("%lld\n", result);
	}
	
	return 0;
}
