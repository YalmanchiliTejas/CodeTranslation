#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<stack>
#include<map>
#include<cstdint>
#include<unordered_map>
#include<boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < ( int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second


namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>h(n);
	rep(i, n) {
		cin >> h[i];
	}
	int count = 0;
	rep(i, n) {
		bool ans = true;
		rep(j, i) {
			if (h[j] > h[i]) {
				ans = false;
			}
		}
		if (ans) {
			count++;
		}
	}
	cout << count << endl;
}