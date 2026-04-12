#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(obj)   (obj).begin(),(obj).end()

#define debug(var)  do{std::cout << __LINE__ << "> " << #var << ": ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

template<typename T>
struct CumulativeSum {
    vector<T> s;
    CumulativeSum(const vector<T> &nums) {
        int n = nums.size();
        s.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }
    // [l, r), l and r is 0-indexed.
    T sum(int l, int r) {
        return s[r] - s[l];
    }
};

void Main() {
	ll N, X, M; cin >> N >> X >> M;
	ll A = X % M;
	map<ll, ll> mp;
	vl ar;
	mp[A] = 0;
	ar.push_back(A);
	// [)
	int loop_start = -1;
	int loop_end = -1;
	FOR(i,1,N) {
		ll tmp = (A * A) % M;
		if (mp.count(tmp) != 0) {
			loop_start = mp[tmp];
			loop_end = i;
			break;
		} else {
			mp[tmp] = i;
		}
		A = tmp;
		ar.push_back(A);
	}
	CumulativeSum<ll> cs(ar);
	if (loop_end == -1 || N < loop_end) {
		cout << cs.sum(0, N) << endl;
	} else {
		ll tmp = N - loop_end;
		ll tmp2 = tmp / (loop_end - loop_start);
		ll tmp3 = tmp % (loop_end - loop_start);
		cout << cs.sum(0, loop_start) + cs.sum(loop_start, loop_end) * (tmp2 + 1) + cs.sum(loop_start, loop_start + tmp3) << endl;
	}
}

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
