//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef int64_t LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)
#define EACH(i,c) for(decltype((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) whole(sort, c)
#define RSORT(c) rwhole(sort, c)

//constant
//--------------------------------------------
constexpr double EPS = 1e-10;
constexpr double PI  = M_PI;
constexpr int MOD = 1000000007;

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

// 多重vector
// auto dp=make_v<int>(4,h,w) みたいに使える
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

// 多重vectorのためのfill
// fill_v(dp,0) みたいに使える
template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

template<class T,class U> void chmax(T&a,U b){if(a<b)a=b;}
template<class T,class U> void chmin(T&a,U b){if(b<a)a=b;}
LL gcd(LL a, LL b) { return b?gcd(b,a%b):a;}
LL lcm(LL a, LL b) { return a/gcd(a,b)*b;}

//main code

int main(int argc, char *argv[])
{
	int n,m;
	cin >> n >> m;
	if (n == m) {cout << "Yes" << endl;}
	else {cout << "No" << endl;}
	return 0;
}
