#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
#define Length 80000
using namespace std;
typedef pair<ll, ll> P;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool used[110];

bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
	return a.first * a.first + a.second * a.second > b.first*b.first + b.second * b.second;
}

void solve(int n) {
	vector<pair<int, int>>p(n), q(n);
	for (int i = 0;i < n;i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0;i < n;i++) {
		cin >> q[i].first >> q[i].second;
	}
	int dist = Length, flag = 0;
	int ans = 0;
	sort(p.begin(), p.end());
	for (int i = 0;i < n;i++) {
		dist = Length;
		flag = 0;
		for (int j = 0;j < n;j++) {
			if (!used[j]) {
				int x = q[j].first - p[i].first;
				int y = q[j].second - p[i].second;
				if ((x > 0) && (y > 0) && y < dist) {
					dist = y;
					flag = j;
				}
			}
		}
		if (dist < Length) {
			ans++;
			used[flag] = true;
		}
	}
	cout << ans << endl;
}

ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

ll Q[110];
	
int main(void){
	ll a, b, c, x, y, ans = 1000000000000000;
	cin >> a >> b >> c >> x >> y;
	for (ll i = 0;i <= 100000;i++) {
		ll A = max(a*(x - i), (ll)0);
		ll B = max(b*(y - i), (ll)0);
		ll C = 2 * c*i;
		ans = min(ans, A + B + C);
	}
	cout << ans << endl;
	return 0;
}