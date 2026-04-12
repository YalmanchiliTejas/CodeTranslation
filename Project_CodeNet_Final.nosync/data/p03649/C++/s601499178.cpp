#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int N; ll A[55];

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%lld", A+i);
	ll t = 0;
	for(int i=1;i<=N;i++) {
		t += A[i] / (N + 1);
	}
	for(int i=1;i<=N;i++) A[i] = A[i] % (N + 1) + t;
	ll r = max(0LL, *max_element(A+1, A+1+N) - 3 * N);
	t += r * N;
	for(int i=1;i<=N;i++) A[i] -= r;
	while(1) {
		int f = -1;
		for(int i=1;i<=N;i++) if(A[i] >= N) { f = i; break; }
		if(f == -1) break;
		A[f] -= N+1;
		for(int i=1;i<=N;i++) A[i]++; ++t;
	}
	printf("%lld\n", t);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}