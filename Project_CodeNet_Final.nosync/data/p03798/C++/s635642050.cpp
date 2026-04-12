#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<int, int>
#define sz(x) x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<int>
#define COUT(x) cout<<(x)<<endl
#define MA map<int,int>
#define SE set<int>
#define PQ priority_queue


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}


const long long MOD = 1000000007;
const long long INF = 1LL << 50;

// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))

int N; string S;
bool ani[100010];
bool greedy(bool f1, bool f2) {
	ani[0] = f1;
	ani[1] = f2;
	for (int i = 2; i < N; ++i) {
		ani[i] = ((S[i - 1] == 'o') ^ ani[i - 1]) ^ ani[i - 2];
	}
	return (ani[1] ^ ani[N - 1]) ^ (S[0] == 'o') == ani[0] && (ani[N - 2] ^ ani[0]) ^ (S[N - 1] == 'o') == ani[N - 1];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
		if (greedy(i < 2, i % 2 < 1)) {
			flag = true;
			break;
		}
	}
	if (flag) {
		for (int i = 0; i < N; ++i) cout << (ani[i] ? 'S' : 'W');
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}