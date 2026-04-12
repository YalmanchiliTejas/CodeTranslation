#include "bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	lint N;
	cin >> N;
	vector<lint> vec(N);
	REP(i, N) {
		cin >> vec[i];
	}
	sort(ALL(vec));
	lint sum = 0;
	if (N % 2 == 0) {
		REP(i, N / 2 - 1) {
			sum += (vec[N - i - 1] * 2);
			sum -= (vec[i] * 2);
		}
		sum += vec[N / 2];
		sum -= vec[N / 2 - 1];
	}
	else {
		lint sum1 = 0, sum2 = 0;
		REP(i, N / 2 - 1) {
			sum1 += (vec[N - i - 1] * 2);
			sum1 -= (vec[i] * 2);
		}
		sum1 += (vec[N / 2 + 1] * 2);
		sum1 -= (vec[N / 2] + vec[N / 2 - 1]);
		REP(i, N / 2 - 1) {
			sum2 += (vec[N - i - 1] * 2);
			sum2 -= (vec[i] * 2);
		}
		sum2 -= (vec[N / 2 - 1] * 2);
		sum2 += (vec[N / 2] + vec[N / 2 + 1]);
		sum = max(sum1, sum2);
	}
	cout << sum << endl;
}
