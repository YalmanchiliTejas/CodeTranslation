#include<cstdio>
#include<cstring>
#include<cmath>
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

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define REP(i,n) for(int i = 0;i < n;i++)
#define FOR(i,a,b) for(int i = a;i < b;i++)
#define MEM(a,b) memset(a,b,sizeof(a))
#define ALL(x) (x).begin(),(x).end()
#define LMAX 9223372036854775807
#define LMIN -9223372036854775808

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ull, ull> UP;
typedef tuple<int, int, int> T;

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
	if (a < b)swap(a, b);
	int k = a % b;
	if (k == 1)return 1;
	if (k == 0)return b;
	int ans = gcd(b, k);
	return ans;
}
ll digisum(ll a) {
	int sum = 0;
	while (a) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}
ll countpow(ll a, ll b) {
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


int main() {
	IOS;
	char a;
	cin >> a;
	char boin[] = { 'a','i','u','e','o' };
	bool ans = false;
	REP(i, 5)if (a == boin[i])ans = true;
	cout << (ans ? "vowel" : "consonant") << endl;
}

