//------------------------------>> tsukasa_diary's template <<------------------------------//
#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define allof(a) (a).begin(),(a).end()
using lint = long long;
template< typename T > using Vec = vector< T >;

template< typename T > bool inRange(T x, T lb, T ub) { return lb <= x && x < ub; }
template< typename T > bool inRange(T x, T y, T lb, T ub) { return in_range(x, lb, ub) && in_range(y, lb, ub); }
template< typename T > void modAdd(T& a, T b, T mod) { a = (a + b + mod) % mod; }
template< typename T > void modMul(T& a, T b, T mod) { a = (a * b) % mod; }
template< typename T > void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > void maxUpdate(T& a, T b) { a = max(a, b); }
inline int bitCount(int x) { return __builtin_popcount(x); }
inline int bitCount(lint x) { return __builtin_popcountll(x); }

const int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
const int Dx[8] = {0,1,1,1,0,-1,-1,-1}, Dy[8] = {-1,-1,0,1,1,1,0,-1};
const double PI = acos(-1);

//--------------8---------------->> coding space <<-----------------8-------------//
// Segment Tree
template< typename DATA, DATA FAIL >
class SegmentTree {
private:
	int size__;
	Vec< DATA > data;
	
	inline int left_t(int k) { return (k << 1) + 1; }
	inline int right_t(int k) { return (k << 1) + 2; }
	inline int center(int l, int r) { return (l + r) >> 1; }
	
	DATA calc(DATA d1, DATA d2) { return max(d1, d2); }
	
	DATA query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return FAIL;
		if (a <= l && r <= b) return data[k];
		return calc(query(a, b, left_t(k), l, center(l, r)),
					query(a, b, right_t(k), center(l, r), r));
	}
	
public:
	SegmentTree(int n, DATA ini) {
		for (size__ = 1; size__ < n; size__ <<= 1);
		data.assign(2 * size__ - 1, ini);
	}
	
	void update(int k, DATA a) {
		k += size__ - 1;
		data[k] = a;
		
		while (k > 0) {
			k = (k - 1) >> 1;
			data[k] = calc(data[left_t(k)], data[right_t(k)]);
		}
	}
	
	DATA query(int a, int b) { return query(a, b, 0, 0, size__); }
	
	int size() { return size__; }
};

int main() {
	int N;
	cin >> N;
	
	Vec< int > A(N);
	for_(i,0,N) cin >> A[i];
	
	SegmentTree< int, -1 > seg(N+1, (int)0);
	for_(i,0,N) seg.update(i, A[i]);
	
	int ans = 0;
	Vec< bool > vis(N, false);
	for_(i,0,N) {
		if (!vis[i]) {
			int cur = i;
			++ans;
			while (1) {
				vis[cur] = true;
				//cerr << A[cur] << " ";
				int lb = cur, ub = N;
				while (ub - lb > 1) {
					int med = (lb + ub) / 2;
					if (seg.query(cur, med+1) > A[cur]) ub = med;
					else lb = med;
				}
				if (ub == N) break;
				seg.update(ub, -1);
				cur = ub;
			}
			//cerr << endl << endl;
		}
	}
	cout << ans << endl;
}
//--------------8---------------->> coding space <<-----------------8-------------//