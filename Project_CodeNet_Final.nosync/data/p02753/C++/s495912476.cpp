#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#include<cstring>
#include<deque>
#include<map>
#include<iomanip>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define VE vector<int>
#define VEP vector<pair<int,int>>
#define llong long long
#define pb(a) push_back(a)
using namespace std;
const vector<VE> DIR{ {-1,0},{1,0},{0,-1},{0,1} };
const llong MOD = 1000000007;
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
template<class T>
int range_check(int val, int min, int max) {
	if (val < min) {
		return -1;
	}
	if (val > max) {
		return -1;
	}
	return val;
}
template<class T,class T1>
bool array_find(const T& array, const T1& dst) {
	auto result = find(array.first(), array.end(), dst);
	if (result == array.end()) {
		return false;
	}
	else {
		return true;
	}
}
int main() {
	string str;
	cin >> str;
	if (str == "AAA" || str == "BBB") {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}
