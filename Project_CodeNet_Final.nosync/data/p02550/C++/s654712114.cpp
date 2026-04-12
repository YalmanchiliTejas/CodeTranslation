//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
using LL = int64_t;
using VL = vector<LL>;
using VVL = vector<VL>;
using VS = vector<string>;
using PLL = pair<LL, LL>;

//container util
//------------------------------------------
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)
#define EACH(i,c) for(decltype((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define ALL(x) ::std::begin(x), ::std::end(x)
#define RALL(x) ::std::rbegin(x), ::std::rend(x)
#define SORT(c) whole(sort, c)
#define RSORT(c) rwhole(sort, c)

//constant
//--------------------------------------------
constexpr double EPS = 1e-10;
constexpr double PI  = 3.14159265358979323846;
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
// declaretion
template<typename T> istream& operator >>(istream& is, vector<T>& vec);
template<typename T1, typename T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p);
template<typename T> ostream& operator <<(ostream& os, const vector<T>& vec);
template<typename T> ostream& operator <<(ostream& os, const vector<vector<T>>& vv);
template<typename T> vector<T> make_v(size_t a);
template<typename T,typename... Ts> auto make_v(size_t a,Ts... ts);
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v);
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v);

// implementation
template<typename T>
istream& operator >>(istream& is, vector<T>& vec) {
	for(T& x: vec) is >> x;
	return is;
}
template<typename T1, typename T2>
ostream& operator <<(ostream& os, const pair<T1, T2>& p) {
	os << p.first << "," << p.second;
	return os;
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

template<class T,class U> bool chmax(T&a,U b){if(a<b){a=b;return true;}return false;}
template<class T,class U> bool chmin(T&a,U b){if(b<a){a=b;return true;}return false;}
template<typename T> T gcd(T a, T b) { return b?gcd(b,a%b):a;}
template<typename T> T lcm(T a, T b) { return a/gcd(a,b)*b;}

//main code

int main(int argc, char *argv[])
{
	LL n,x,m;
	cin >> n >> x >> m;
	LL a = x;
	VL mods = {a};
	vector<bool> deta(100001,false);
	deta[x] = true;
	LL start = -1; // 繰返しのスタート
	for (int i = 1; i < min((LL)100000,n); i++) {
		LL na = (a*a)%m;
		if (deta[na]) {
			start = na;
			break;
		} else {
			deta[na] = true;
			mods.push_back(na);
		}
		a = na;
	}
	LL ans = accumulate(ALL(mods),(LL)0);
	if(start == -1) {
		cout << ans << endl;
		return 0;
	}
	LL start_i = 0;
	for (int i = 0; i < mods.size(); i++) {
		if (start == mods[i]) {
			start_i = i;
			break;
		}
	}
	dump(mods);
	LL kl = mods.size() - start_i;
	LL kls = 0;
	for (int i = start_i; i < mods.size(); i++) {
		kls += mods[i];
	}
	n -= mods.size();
	ans += kls*(n/kl);
	dump(kl);
	for (int i = 0; i < n%kl; i++) {
		ans += mods[start_i+i];
	}
	cout << ans << endl;
	return 0;
}