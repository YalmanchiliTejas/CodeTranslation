#define _USE_MATH_DEFINES
#include<cmath>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<tuple>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<functional>
#include<iomanip>
#include<random>
using namespace std;


#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define REP(i,n) for(int i = 0;i < n;i++)
#define FOR(i,a,b) for(int i = a;i < b;i++)
#define ALL(x) (x).begin(),(x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	void unionSet(int x, int y) {
		x = root(x), y = root(y);
		if (x != y) {
			if (data[y] < data[x])swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll digitsum(ll a) {
	int sum = 0;
	while (a) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}
int getdigit(ll a) {
	return to_string(a).size();
}
int countpow(ll a, ll b) {
	int ans = 0;
	if (b == 0)return -1;
	while (1) {
		if (a % b == 0) {
			a /= b;
			ans++;
		}
		else break;
	}
	return ans;
}
int to_num(char c) {
	if (c >= '0' && c <= '9')return (c - '0');
	else return -1;
}



int main() {
	IOS;
	int n;
	cin >> n;
	deque<ll> que;
	REP(i, n) {
		ll s;
		cin >> s;
		if (i % 2 == 0) {
			que.push_front(s);
		}
		else {
			que.push_back(s);
		}
	}
	if (n % 2 == 0)reverse(ALL(que));
	REP(i, que.size()) {
		if (i)cout << ' ';
		cout << que[i];
	}
	cout << endl;
}