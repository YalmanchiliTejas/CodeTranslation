#include "bits/stdc++.h"
#include<random>
using namespace std;
typedef long long int lint;
typedef pair<lint, lint> plint;
typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7, INF = 1e18;

lint N, arr[100000];
int main() {
	cin >> N;
	REP(i, N) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	lint sum = 0;
	if (N % 2 == 0) {
		lint sum = 0;
		REP(i, N/2 - 1) {
			sum += arr[N - i - 1] * 2;
			sum -= arr[i] * 2;
		}
		sum += arr[N / 2];
		sum -= arr[N / 2 - 1];
		cout << sum << endl;
	}
	else {
		lint sum1 = 0, sum2 = 0;
		sum1 -= arr[N / 2] + arr[N / 2 - 1];
		REP(i, N / 2 - 1) {
			sum1 -= arr[i] * 2;
		}
		REP(i, N / 2) {
			sum1 += arr[N - i - 1] * 2;
		}

		sum2 += arr[N / 2] + arr[N / 2 + 1];
		REP(i, N / 2 - 1) {
			sum2 += arr[N - i - 1] * 2;
		}
		REP(i, N / 2) {
			sum2 -= arr[i] * 2;
		}
		cout << max(sum1, sum2);
	}
}
