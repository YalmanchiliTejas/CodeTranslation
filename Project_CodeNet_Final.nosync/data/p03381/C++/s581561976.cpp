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
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	rep(i,N) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(all(a));
	rep(i,N) {
		if(a[N/2] <= b[i])
			cout << a[N/2-1] << endl;
		else
			cout << a[N/2] << endl;
	}
	return 0;
}
