//事前知識：vectorは必須。(仕組みが知りたければ、エイリアステンプレート、auto型、範囲for文を調べることを推奨）


//macの場合は準備が必要。
//既存のXcodeに付属しているg++は古いケースも多いので、https://qiita.com/wawawa/items/50c2c612b0937f28d92b　の通りにやって最新版を使えるようにする。
//5行目はmacには標準装備されてないので、自分で用意する必要がある。https://qiita.com/flowerrr__lily/items/28a20062e957fa10b7a7　の通りにやろう。

//標準ライブラリの一括インストール
#include <bits/stdc++.h>
using namespace std;

//int系宣言（long long型はよく使うので省略して書けるようにしてる）
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;

//多次元配列宣言
template<typename T> using vec2d = vector<vector<T>>;
template<typename T> using vec3d = vector<vector<vector<T>>>;
template<typename T> using vec4d = vector<vector<vector<vector<T>>>>;
template<typename T> using vec5d = vector<vector<vector<vector<vector<T>>>>>;

//?
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

//for文
#define for00(i, n) for(lint i=0,i##_end_=(n);i<i##_end_;i++)
#define for10(i, n) for(lint i=1,i##_end_=(n);i<i##_end_;i++)
#define for01(i, n) for(lint i=0,i##_end_=(n);i<=i##_end_;i++)
#define for11(i, n) for(lint i=1,i##_end_=(n);i<=i##_end_;i++)
#define formn(i, m, n) for(lint i=(m),i##_end_=(n);i<=i##_end_;i++)

#define forin(x, vec) for(auto (x) : (vec))

//cin, coutでvector等を一括で入出力
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto it=vec.begin();it!=vec.end();it++){ os << *it; auto it2 = it;it2++;if(it2 != vec.end()){cout << ",";}} os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }

//多次元vectorのコンストラクタ
template<typename T> vec2d<T> make2d(lint L, lint M, T value){ vec2d<T> ans(M, vector<T>(L, value)); return ans;}
template<typename T> vec3d<T> make3d(lint L, lint M, lint N, T value){ vec3d<T> ans(N,vec2d<T>(M, vector<T>(L, value))); return ans;}
template<typename T> vec4d<T> make4d(lint L, lint M, lint N, lint O, T value){ vec4d<T> ans(O, vec3d<T>(N,vec2d<T>(M, vector<T>(L, value)))); return ans;}
template<typename T> vec5d<T> make5d(lint L, lint M, lint N, lint O, lint P, T value){vec5d<T> ans(O,vec4d<T>(O, vec3d<T>(N,vec2d<T>(M, vector<T>(L, value))))); return ans;}

//vectorの要素を一括設定
template<typename T> void setAll1d(vector<T>& vec, T value){for(auto& v : vec){v = value;}}
template<typename T> void setAll2d(vec2d<T>& vec, T value){for(auto& v1 : vec){for(auto& v2 : v1){v2 = value;}}}
template<typename T> void setAll3d(vec3d<T>& vec, T value){for(auto& v3 : vec){for(auto& v2 : v3){for(auto& v1 : v2){v1 = value;}}}}
template<typename T> void setAll4d(vec4d<T>& vec, T value){for(auto& v4 : vec){for(auto& v3 : v4){for(auto& v2 : v3){for(auto& v1 : v2){v1 = value;}}}}}
template<typename T> void setAll5d(vec5d<T>& vec, T value){for(auto& v5 : vec){for(auto& v4 : v5){for(auto& v3 : v4){for(auto& v2 : v3){for(auto& v1 : v2){v1 = value;}}}}}}

//2,3次元vectorを綺麗にcout
template<typename T>void vout2d(vec2d<T> vec){cout << "[" << endl;forin(v, vec){cout << "  " << v << endl;}cout << "]" << endl;}
template<typename T>void vout3d(vec2d<T> vec){cout << "[" << endl;forin(v,vec){cout << "  [" << endl;forin(x,v){cout << "    " << x << endl;}cout << "  ]" << endl;}cout << "]" << endl;}

//最大公約数
lint gcp(lint a, lint b){if (a > b) return (gcp(b,a));if (a ==0) return (0);lint r = 1;while(1){r = b % a;if (r == 0) break;b = a;a = r;}return (a);}

//lintの階乗と累乗（modで割った余り。mod=0とするとそのまま）
lint factorial(lint n, lint mod){if(n <= 1) return 1;if(mod == 0) return (n*factorial(n-1,0));return (n * factorial(n-1,mod)%mod);}
lint power(lint num, lint n, lint mod)
{if(n ==0) return 1;if(num == 0) return 0;if(mod == 0) return (num*power(num,n-1,0));return (num*power(num,n-1,mod)%mod);}

//lintのn桁目の数字を返す
lint nget(lint num, lint n){return (num%power(10,n,0)/power(10,n-1,0));}



int main(){
	string s;
	cin >> s;

	if (s=="AAA" || s=="BBB")
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

  return 0;
}

