#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

ll a[55];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	int N;
	cin >> N;
	ll sum = 0;
	ll M = -inf;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
		M = max(a[i], M);
	}


	if (M > 1000) {
		ll X = sum - N * (N - 1);
		ans = X;
		for (int i = 0; i < N; i++)a[i] += X;

		ll D = N + 1;
		ll ok = inf,ng = 0;
		while (ok - ng > 1) {
			ll mid = (ok + ng) / 2LL;
			ll temp = 0;
			for (int i = 0; i < N; i++)temp += max(0LL,(a[i]-mid)/D);
			if (temp <= X)ok = mid;
			else ng = mid;
		}
		ll tempsum = 0;
		for (int i = 0; i < N; i++) {
			tempsum += max(0LL, (a[i] - ok) / D);
			a[i] = max(0LL,a[i] - ((a[i]-ok)/D)*D);
		}
		for (int i = 0; i < X-tempsum; i++) {
			int id = -1;
			int ma = -1;
			for (int i = 0; i < N; i++)if (a[i] > ma) { id = i, ma = a[i]; };
			for (int i = 0; i < N; i++)if (i == id)a[i] -= D;
		}
	}


	//simulation
	while(1){
		int id = -1;
		ll ma = -inf;
		for (int i = 0; i < N; i++) {
			if (a[i] > ma) { id = i, ma = a[i]; };
		}
		if (ma <= N - 1)break;
		for (int i = 0; i < N; i++) {
			if (i != id)a[i]++;
			else a[i] -= N;
		}
		ans++;
	}
	puts(ans);

	
	return 0;
}
