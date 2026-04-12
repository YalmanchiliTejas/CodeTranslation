#include <bits/stdc++.h>

using ll = long long;
#define int ll

namespace ext {
	template <class T>
	struct vec_type;
	template <class T>
	constexpr bool is_vec_v;
	using namespace std;
	template<class T>
	struct Vector : std::vector<T> {
		using std::vector<T>::vector;
		char dil = ' ';
		Vector<T> accum() {
			Vector<T> res(this->size() + 1);
			for (size_t i = 0; i < this->size(); i++) {
				res[i+1] = (*this)[i] + res[i];
			}
			return res;
		}
		template<class U = T>
		typename enable_if<is_vec_v<U>, Vector<T>>::type accum2D() {
			const size_t H = this->size();
			const size_t W = (*this)[0].size();
			using S = typename vec_type<U>::type;
			Vector<T> res(H + 1, Vector<S>(W + 1));
			for (size_t i = 0; i < H; i++) {
				for (size_t j = 0; j < W; j++) {
					res[i+1][j+1] = (*this)[i][j];
					res[i+1][j+1] += res[i][j+1];
					res[i+1][j+1] += res[i+1][j];
					res[i+1][j+1] -= res[i][j];
				}
			}
			return res;
		}
		Vector<T> zaatsu() {
			map<T, int> m;
			for (auto& e: *this) m[e] = 1;
			int count = 0;
			for (auto& e: m) e.second = count++;
			Vector<T> res = *this;
			for (auto& e: res) e = m[e];
			return res;
		}
		friend istream& operator>>(istream& is, Vector<T>& t) {
			for (auto& e: t) cin >> e;
			return is;
		}
		friend ostream& operator<<(ostream& os, Vector<T>& t) {
			t.print(' ', os);
			return os;
		}
		void print(char del = ' ', ostream& os = cout) {
			for (size_t i = 0; i < this->size(); i++) {
				os << (*this)[i];
				if (i + 1 != this->size()) os << del;
				os.flush();
			}
		}
		void println(char del = ' ', ostream& os = cout) {
			print(del, os);
			cout << endl;
		}
		long long crossing_merge() {
			auto t = *this;
			return t.crossing_merge_sub();
		}
		// [min_v, max_v)
		long long crossing_bit(T min_v = -1, T max_v = -1) {
			if (min_v == -1) min_v = this->min();
			if (max_v == -1) max_v = this->max() + 1;
			Vector<T> bit(max_v - min_v + 1, 0);
			long long res = 0;
			for (auto e: *this) {
				e = max_v - e;
				for (size_t x = e - 1; x; x -= x & -x) {
					res += bit[x];
				}
				for (size_t x = e; x < bit.size() ; x += x & -x) {
					bit[x]++;
				}
			}
			return res;
		}
		bool permutation() {
			return next_permutation(this->begin(), this->end());
		}
		T& max() {
			return *max_element(this->begin(), this->end());
		}
		T& min() {
			return *min_element(this->begin(), this->end());
		}
private:
		long long crossing_merge_sub() {
			if (this->size() == 1) return 0;
			int x = this->size() / 2;
			Vector<T> left(this->begin(), this->begin() + x);
			Vector<T> right(this->begin() + x, this->end());
			long long res = left.crossing_merge_sub() + right.crossing_merge_sub();
			left.push_back(numeric_limits<T>::max()); right.push_back(numeric_limits<T>::max());
			size_t l = 0, r = 0;
			while (l + r < this->size()) {
				if (left[l] < right[r]) {
					(*this)[l+r] = left[l];
					l++;
				} else {
					(*this)[l+r] = right[r];
					r++;
					res += x - l;
				}
			}
			return res;
		}
	};
	template <class T>
	struct vec_type : std::false_type {};
	template <class T>
	struct vec_type<Vector<T>> : std::true_type {
		using type = T;
	};
	template <class T>
	constexpr bool is_vec_v = vec_type<T>::value;
}

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
#define MINV(v) min_element(all(v))
#define MAXV(v) max_element(all(v))
#define MIN3(a, b, c) min(min(a, b), c)
#define MIN4(a, b, c, d) min(MIN3(a, b, c), d)
#define MIN5(a, b, c, d, e) min(MIN4(a, b, c, d), e)
#define MIN6(a, b, c, d, e, f) min(MIN5(a, b, c, d, e), f)
#define MAX3(a, b, c) max(max(a, b), c)
#define MAX4(a, b, c, d) max(MAX3(a, b, c), d)
#define MAX5(a, b, c, d, e) max(MAX4(a, b, c, d), e)
#define MAX6(a, b, c, d, e, f) max(MAX5(a, b, c, d, e), f)
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmin3(a, b, c) a = MIN3(a, (b), (c))
#define chmin4(a, b, c, d) a = MIN4(a, (b), (c), (d))
#define chmin5(a, b, c, d, e) a = MIN5(a, (b), (c), (d), (e))
#define chmin6(a, b, c, d, e, f) a = MIN6(a, (b), (c), (d), (e), (f))
#define chmax(a, b) a = max(a, (b))
#define chmax3(a, b, c) a = MAX3(a, (b), (c))
#define chmax4(a, b, c, d) a = MAX4(a, (b), (c), (d))
#define chmax5(a, b, c, d, e) a = MAX5(a, (b), (c), (d), (e))
#define chmax6(a, b, c, d, e, f) a = MAX6(a, (b), (c), (d), (e), (f))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

using namespace std;
using namespace ext;

const string YES_STR = "Yes";
const string NO_STR = "No";

void solve(long long N, long long M){
	YES(N == M);
}

// Generated by 1.1.6 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
signed main(){
	long long N;
	scanf("%lld",&N);
	long long M;
	scanf("%lld",&M);
	solve(N, M);
	return 0;
}
