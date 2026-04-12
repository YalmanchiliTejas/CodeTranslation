#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;
#define int ll

signed main() {
	int ans = 0;
	int N, X, M; cin >> N >> X >> M;
	if (X == 0 && M == 1) {
		cout << 0 << endl; return 0;
	}
	vector<int> ordVisit(M, -1);
	int val = X;
	int Lcycle = -1;
	int Sumcycle = 0;
	int Startcycle = -1;
	//Aの値で既出があればおしまい
	// ordvistのvaluesは1-indexed
	for (int i = 1; i < M+1; i++) {
		//とりあえずループ探し
		if (ordVisit[val] > 0) {
			Startcycle = val;
			Lcycle = i - ordVisit[val];
			break;
		}
		ordVisit[val] = i;
		val *= val; val %= M;
	}
	int ind = Startcycle;
	for (int p = 0; p < Lcycle;p++) {
		Sumcycle += ind;
		ind *= ind; ind %= M;
	}
		
	// [X,loopind)の数を数える
	int Dfirst= 0;
	int tmp = X;
	while (tmp != Startcycle) {
		Dfirst++;
		ans += tmp;
		tmp *= tmp; tmp %= M;
	}

	int rem = N - Dfirst;
	int Tloop = rem / Lcycle;
	int Dsecond = rem % Lcycle;

	ans += Tloop * Sumcycle;

	int tmpp = Startcycle;

	for (int i = 0; i < Dsecond; i++) {
		ans += tmpp;
		tmpp *= tmpp; tmpp %= M;
	}
	cout << ans << endl;
}