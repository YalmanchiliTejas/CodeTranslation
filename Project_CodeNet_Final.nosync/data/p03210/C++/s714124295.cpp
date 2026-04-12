#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i))
#define mat(type, c, m, n) vector<vector<type>> c(m, vector<type>(n));for(auto& r:c)for(auto& i:r)cin>>i;
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a), i##_len=(n); i>i##_len; --i)
#define each(x,y) for(auto &(x):(y))
#define var(type, ...)type __VA_ARGS__;Scan(__VA_ARGS__);
template<typename T> void Scan(T& t) { cin >> t; }
template<typename First, typename...Rest>void Scan(First& first, Rest&...rest) { cin >> first; Scan(rest...); }
#define vec(type, c, n) vector<type> c(n);for(auto& i:c) cin>>i;
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
#define em emplace
#define pb pop_back
#define fi first
#define se second
#define get(a, i) get<i>(a)
#define bit_count __builtin_popcount
#define mt make_tuple
inline string zero(int a,string s,char c='0'){return string(a-len(s),c)+s;}
inline string zero(int a,int t,char c='0'){return zero(a, to_string(t), c);}
inline string zero(int a,ll t,char c='0'){return zero(a, to_string(t), c);}
#define mini min_element
#define maxi max_element
#define sum accumulate
#define chmax(a,b) if(a<b)a=b
#define chmin(a,b) if(a>b)a=b
template <class T> inline void print(T t){cout << t << '\n';}
template <class H, class... T> inline void print(H h, T... t){cout << h << " ";print(t...);}
int main() {
	var(int, x);
	print(x == 3 || x == 5 || x == 7 ? "YES" : "NO");
	return 0;
}
