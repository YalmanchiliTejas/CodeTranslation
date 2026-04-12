#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <utility>

#include <cassert>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define FOR(i,a,b) for(ll i=(a); i < (b); i++)
#define RFOR(i,a,b) for(ll i=(b)-1; i >= (a); i--)
#define rep(i,n) FOR(i,0,(n))
#define rrep(i,n) RFOR(i,0,(n))

int main() {
	ll N, K;
	cin >> N >> K;
	ll res = 0;
	if(K == 0) {
		res = N*N;
	}
	else {
		for(ll b = K+1; b <= N; b++) {
			res += (N/b)*(b-K) + max(N%b-(K-1), 0ll);
		}
	}
	cout << res << endl;
	return 0;
}
