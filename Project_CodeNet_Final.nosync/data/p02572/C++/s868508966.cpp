#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debarr(a,x,y)cerr<<#a<<":";for(int i=x;i<=y;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define deb(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S, class T>ostream &operator<<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << "," << p.second << ")";}
template<class T>ostream &operator<<(ostream &os, const vector<T> &p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const set<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const multiset<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class S, class T>ostream &operator<<(ostream &os, const map<S, T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>void dbs(string str, T t) {cerr << str << ":" << t << "\n";}
template<class T, class...S>void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
#else
#define deb(...){}
#define debarr(a,x,y){}
#define debmat(mat,row,col){}
#endif
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define pr(x) {cout << x << "\n"; return;}

#define int              long long
#define ll               long long
#define ld               long double
#define fi               first
#define se               second
#define mp               make_pair
#define pb               push_back
#define sz(x)            (int)x.size()
#define all(x)           x.begin(),x.end()
#define ini(x,y)         memset(x,y,sizeof(x))
#define rep(i,n)         for(int i=0;i<n;i++)
#define re(i,n)          for(int i=1;i<=n;i++)
#define fr(i,a,b)        for(int i=a;i<=b;i++)
#define fb(i,a,b)        for(int i=a;i>=b;i--)
typedef pair<int, int>   pii;
typedef vector<int>      vi;
typedef vector<pii>      vii;
typedef map<int, int>    mii;
typedef set<int>         si;
const int N = 5e3 + 10;
const int mod = 1e9 + 7;

void add(int &a, int b) { a = (a + b) % mod;}
int mul(int a, int b) { return a % mod * b % mod % mod;}
void solve(int tc)
{
	int n; cin >> n;
	int ans = 0, sum = 0;
	rep(i, n)
	{
		int x; cin >> x;
		add(ans, mul(sum, x));
		sum += x;
	}
	cout << ans << endl;




}
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}