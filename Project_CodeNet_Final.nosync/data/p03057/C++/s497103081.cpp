#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	string S;
	cin >> N >> M >> S;
	cat mod = 1000000007;
	vector<int> L;
	for(int i = 0; i < M; i++) if(i == 0 || S[i] != S[i-1]) {
		int l = 0;
		while(i+l < M && S[i+l] == S[i]) l++;
		L.push_back(l);
	}
	M = L.size();

	if(M == 1) {
		vector<cat> cnt(N+1, 0);
		cnt[1] = 1;
		cat pref = 1;
		for(int i = 2; i <= N; i++) {
			cnt[i] = (pref - cnt[i-1]) % mod;
			pref = (pref + cnt[i]) % mod;
		}
		cat ans = 1;
		for(int i = 1; i < N; i++)
			ans = (ans + (i+1) * cnt[N-i]) % mod;
		cout << ans << "\n";
		return 0;
	}
 
	int max_first = N-1;
	if(L[0]%2 == 0) max_first = min(max_first, L[0]+1);
	for(int i = 0; i < M-1; i += 2)
		if(L[i]%2 != 0) max_first = min(max_first, L[i]);
	if(max_first%2 == 0) max_first--;

	vector<cat> cnt(N+1, 0), pref(N+2, 0);
	cnt[1] = pref[2] = 1;
	for(int i = 3; i <= N; i += 2) {
		cnt[i] = (pref[i-1] - pref[max(0, i-max_first-2)]) % mod;
		pref[i+1] = (cnt[i] + pref[i-1]) % mod;
	}

	cat ans = 0;
	for(int i = 1; i <= max_first; i += 2)
		ans = (ans + (i+1) * cnt[N-i]) % mod;
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
