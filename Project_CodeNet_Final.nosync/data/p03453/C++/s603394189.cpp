#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 30000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
double dot(complex<double> a, complex<double> b) {
	return a.real()* b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real()* b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(cosine);
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa > now_min) {
					now_min = goa;
					now_go = i;
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
pair<long long, long long> seg_tree[seg_size * 4];
pair<long long, long long> seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (n_r <= w_l || w_r <= n_l) return make_pair(0, 0);
	pair<long long, long long> a = seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), b = seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
	a.first += b.first;
	a.second += b.second;
	return a;
}
long long seg_set(int now) {
	seg_tree[now] = make_pair(seg_tree[now * 2].first + seg_tree[now * 2 + 1].first, seg_tree[now * 2].second + seg_tree[now * 2 + 1].second);
	if (now != 1) seg_set(now / 2);
	return 0;
}
long long inv(long long now) {
	long long now_go = MAX_MOD - 2LL;
	long long ans = 1;
	while (now_go != 0) {
		if (now_go % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		now *= now;
		now %= MAX_MOD;
		now_go /= 2;
	}
	return ans;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long combi(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= a - i;
		ans %= MAX_MOD;
		ans *= inv(i + 1);
		ans %= MAX_MOD;
	}
	return ans;
}
pair<long long,long long> dp[2][200000] = {};
long long visited[2][200000];
vector<pair<long long, long long>> vertexs[200000];
int main() {
#define int long long
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	vector<tuple<long long, long long, long long>> edge;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_tuple(a, b, c));
		vertexs[a].push_back(make_pair(b, c));
		vertexs[b].push_back(make_pair(a, c));
	}
	REP(i, n+2) {
		dp[0][i] = make_pair(LONG_INF, 0);
		dp[1][i] = make_pair(LONG_INF, 0);
	}
	for (int te = 0; te < 2; ++te) {
		dp[te][s] = make_pair(0, 1);
		priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> next;
		next.push(make_pair(0LL, s));
		while (next.empty() == false) {
			int now = next.top().second;
			next.pop();
			if (visited[te][now] == 0) {
				visited[te][now] = 1;
				for (int q = 0; q < vertexs[now].size(); ++q) {
					long long cost = vertexs[now][q].second + dp[te][now].first;
					long long next_itr = vertexs[now][q].first;
					if (cost < dp[te][next_itr].first) {
						dp[te][next_itr] = make_pair(cost, 0);
						next.push(make_pair(cost, next_itr));
					}
					if (cost == dp[te][next_itr].first) {
						dp[te][next_itr].second += dp[te][now].second;
						dp[te][next_itr].second %= MAX_MOD;
					}
				}
			}
		}
		swap(s, t);
	}
	long long ans = dp[0][t].second * dp[0][t].second;
	ans %= MAX_MOD;
	for (int i = 1; i <= n; ++i) {
		if (dp[0][i].first == dp[1][i].first&&dp[0][i].first*2LL == dp[0][t].first) {
			//meet there!
			long long geko = dp[0][i].second * dp[1][i].second;
			geko %= MAX_MOD;
			geko *= geko;
			geko %= MAX_MOD;
			ans -= geko;
			ans %= MAX_MOD;
			ans += MAX_MOD;
			ans %= MAX_MOD;
		}
	}
	for (int i = 0; i < edge.size(); ++i) {
		int a = get<0>(edge[i]);
		int b = get<1>(edge[i]);
		int c = get<2>(edge[i]);
		if (dp[0][a].first + dp[1][b].first + c == dp[0][t].first) {
			if (dp[0][a].first*2LL < dp[0][t].first &&dp[1][b].first * 2LL < dp[0][t].first) {
				long long geko = (dp[0][a].second * dp[1][b].second);
				geko %= MAX_MOD;
				geko *= geko;
				geko %= MAX_MOD;
				ans -= geko;
				ans %= MAX_MOD;
				ans += MAX_MOD;
				ans %= MAX_MOD;
				continue;
			}
		}
		if (dp[0][b].first + dp[1][a].first + c == dp[0][t].first) {
			if (dp[0][b].first*2 < dp[0][t].first && dp[1][a].first*2 < dp[0][t].first) {
				long long geko = (dp[1][a].second * dp[0][b].second);
				geko %= MAX_MOD;
				geko *= geko;
				geko %= MAX_MOD;
				ans -= geko;
				ans %= MAX_MOD;
				ans += MAX_MOD;
				ans %= MAX_MOD;
				continue;
			}
		}
	}
	cout << ans << endl;
}