#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct UnionFind{
	vector<int> data;
	UnionFind (int n) : data(n, -1){}

	void Unite(int a, int b){
		a = root(a), b = root(b);
		if (a == b)return;
		if (data[a] > data[b])
			swap(a,b);
		
		data[b] += data[a];
		data[a] = b;
	}

	bool Find(int a, int b){
		return root(a) == root(b);
	}

	int root(int a){
		return data[a] < 0 ? a : data[a] = root(data[a]);
	}

	int size(int a){
		return -data[root(a)];
	}
};

signed main() {
	int n;

	string str;
	cin >> n >> str;

	function<bool(bool a, bool b)> judge = [&](bool a, bool b){
		vector<bool> ans(n);

		ans[0] = a, ans[1] = b;

		
		rep(i, 1, n-1){
			if (str[i] == 'o')
				ans[i + 1] = ans[i] ? ans[i - 1] : !ans[i - 1];
			if (str[i] == 'x')
				ans[i + 1] = ans[i] ? !ans[i - 1] : ans[i - 1];
		}

		bool ret = 1;

		if (str[n - 1] == 'o'){
			if (ans[n - 1]){
				ret = ans[n - 2] == ans[0];
			}
			else
				ret = ans[n - 2] != ans[0];
		}
		else{
			if (ans[n - 1]){
				ret = ans[n - 2] != ans[0];
			}
			else
				ret = ans[n - 2] == ans[0];
		}
		if (ret){
			if (str[0] == 'o'){
				if (ans[0]){
					ret = ans[n - 1] == ans[1];
				}
				else
					ret = ans[n - 1] != ans[1];
			}
			else{
				if (ans[0]){
					ret = ans[n - 1] != ans[1];
				}
				else
					ret = ans[n - 1] == ans[1];
			}
		}

		return ret;
	};

	function<void(bool a, bool b)> output = [&](bool a, bool b){
		vector<bool> ans(n);

		ans[0] = a, ans[1] = b;

		rep(i, 1, n - 1){
			if (str[i] == 'o')
				ans[i + 1] = ans[i] ? ans[i - 1] : !ans[i - 1];
			if (str[i] == 'x')
				ans[i + 1] = ans[i] ? !ans[i - 1] : ans[i - 1];
		}

		for (auto itr : ans){
			printf("%c", itr ? 'S' : 'W');
		}
		printf("\n");
	};

	if (judge(0, 0))
		output(0,0);
	else if (judge(1, 0))
		output(1, 0);
	else if (judge(0, 1))
		output(0, 1);
	else if (judge(1, 1))
		output(1, 1);
	else
		printf("-1\n");

	return 0;
}