#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#include <set>
#include <numeric>
#include <stack>
#include <utility>
#include <time.h>
#include <iterator>
//#include "util.h"

using namespace std;
typedef unsigned uint;
typedef long long lint;
typedef unsigned long long ulint;


//呪文
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { cout << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { cout << "{ }"; return ostr; } cout << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { cout << ", " << *itr; } cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { cout << "{ }"; return ostr; }	cout << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { cout << "{ }"; return ostr; } cout << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
//template <typename T> void print(T* v, int N) { if (N == 0) cout << "{ }"; cout << "{" << v[0]; for (int p = 1; p < N; p++) cout << ", " << v[p]; cout << "}"; }
#define PI 3.14159265358979323846
#define EPS 1e-8
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
	


int main() {
	int n;
	cin >> n;
	cout << n * 800 - (n / 15) * 200 << endl;

	return 0;
}
