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
#define SORT(c) whole(sort, c)
#define RSORT(c) rwhole(sort, c)

//constant
//--------------------------------------------
constexpr double EPS = 1e-10;
constexpr double PI  = M_PI;
constexpr LL MOD = 1000000007;

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

template<class T,class U> void chmax(T&a,U b){if(a<b)a=b;}
template<class T,class U> void chmin(T&a,U b){if(b<a)a=b;}
template<typename T> T gcd(T a, T b) { return b?gcd(b,a%b):a;}
template<typename T> T lcm(T a, T b) { return a/gcd(a,b)*b;}

LL calcNumOfCombination(LL n, LL r){
	LL num = 1;
	for(int i = 1; i <= r; i++){
		num = num * (n - i + 1) / i;
	}
	return num;
}
// a^bの繰り返し二乗法
LL powSquare(LL a, LL b) {
	LL ret = 1;
	while (b > 0) {
		if (b&1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	string n;
	int k;
	cin >> n >> k;
	LL ans = 0;
	for (int i = 1; i < n.size(); i++) {
		// i+1の0からk個0でないものを選ぶ
		// 左端は確定で選ぶ必要がある
		if (i<k) continue;
		ans += calcNumOfCombination(i-1,k-1)*powSquare(9,k);
	}
	if (k == 1) {
		ans += n[0]-'0';
	}
	if (k == 2 and n.size()>1) {
		int t1 = n[0]-'0'-1;
		ans += calcNumOfCombination(n.size()-1,k-1)*9*t1;
		for (int i = 1; i < n.size(); i++) {
			if (n[i]=='0') {continue;}
			int t2 = n[i] - '0';
			ans += t2 + 9*(n.size()-1-i);
			break;
		}
	}
	if (k == 3 and n.size() > 2) {
		int t1 = n[0]-'0'-1;
		ans += calcNumOfCombination(n.size()-1,k-1)*9*9*t1;
		int c = 0;
		for (int i = 1; i < n.size(); i++) {
			if (n[i]=='0') {continue;}
			if (c == 0) {
				int t2 = n[i]-'0'-1;
				ans += (n.size()-1-i)*(t2)*9 + calcNumOfCombination(n.size()-1-i,k-1)*9*9;
				c++;
			}
			else if (c == 1) {
				int t3 = n[i]-'0';
				ans += t3 + 9*(n.size()-1-i);
				break;
			}
		}
	}
	cout << max(ans,(LL)0) << endl;
	return 0;
}
