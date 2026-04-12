//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

// grid
//--------------------------------------------
VL dx = {0, 1, 0, -1};
VL dy = {1, 0, -1, 0};
VL dx2 = {-1, 0, 1, -1, 1, -1, 0, 1};
VL dy2 = {-1, -1, -1, 0, 0, 1, 1, 1};

//debug
//--------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//IO accelerate
//--------------------------------------------
struct InitIO {
    InitIO() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

//template
//--------------------------------------------
template<typename T>
istream& operator >>(istream& is, vector<T>& vec) {
  for(T& x: vec) is >> x;
  return is;
}
template<typename T>
ostream& operator <<(ostream& os, const vector<T>& vec) {
  for(int i=0; i<vec.size(); i++){
    os << vec[i] << ( i+1 == vec.size() ? "" : "\t" );
  }
  return os;
}
template<typename T>
ostream& operator <<(ostream& s, const vector<vector<T>>& vv) {
	for (int i = 0; i < vv.size(); ++i) {
		s << vv[i] << endl;
	}
	return s;
}

//main code
int n;
vector<bool> used(n,false);
const int inf = 99999999;
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
vector<int> lis_fast(const vector<int>& a) {
  const int n = a.size();
  vector<int> A(n, inf);
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[i] = index_of(A, a[i]);
    A[ id[i] ] = a[i];
  }
  int m = *max_element(id.begin(), id.end());
  vector<int> b(m+1);
  for (int i = n-1; i >= 0; --i)
    if (id[i] == m) b[m--] = a[i];
  return b;
}

int main(int argc, char const* argv[])
{
	cin >> n;
	VL a(n);
	cin >> a;
	multiset<int> c; // 最終要素の数
	c.insert(a[0]);
	for (int i = 1; i < n; i++) {
		if (*c.begin() >= a[i]) {
			c.insert(a[i]);
		}
		else {
			auto e = --c.lower_bound(a[i]);
			c.erase(e);
			c.insert(a[i]);
		}
	}
	cout << c.size() << endl;
	return 0;
}
