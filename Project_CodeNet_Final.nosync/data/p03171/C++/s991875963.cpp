/******************************************************/
/******************************************************/
/**                                                  **/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         REAZ AHAMMED CHOWDHURY - reaziii         **/
/**  Department of Computer Science and Engineering  **/
/*         INSTITUTE OF SCIENCE AND TECHNOLOGY       **/
/**                                                  **/
/******************************************************/
/******************************************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pcase(x)     printf("Case %d: ",x++)
#define pn           puts("")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x)     memset(x,-1,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define linfi        LLONG_MAX
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define frx(x,y)     for(int x=0;x<y;x++)
#define fro(i,x,y)   for(int i=x;i<y;i++)
#define ech(x,a)     for(auto &x : a)
#define ff           first
#define ss           second
#define sz(x)        x.size()
#define vi           vector<int>
#define vl           vector<ll>
#define pf           push_front
#define pi           acos(-1.0)

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> void read(T& x) {cin >> x;}
template<class H, class... T> void read(H& h, T&... t) {read(h); read(t...);}
template<class A> void read(vector<A>& x) {for (auto &a : x) read(a);}
template<class J> void print(J& x) {cout << x << " ";}
template<class K> void printn(K& x) {print(x); puts("");}
template<class H> void print(vector<H> &x) {ech(a, x) print(a); puts("");}
template<class J, class... H> void print(J h, H... t) {print(h); print(t...); puts("");}
template<class P> void debug(P h) {
#ifndef ONLINE_JUDGE
	cerr << h << " ";
#endif
}
template<class W, class... V> void debug(W h, V... t) {
#ifndef ONLINE_JUDGE
	debug(h);
	debug(t...);
	cerr << endl;
#endif

}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;

bool checkbitt(ll num, int pos) {return (num >> pos) & 1;}
ll setbitt(ll num, ll pos) {return (1 << pos) | num;}
ll resetbitt(ll num, int pos) {if (!checkbitt(num, pos)) return num; else return (1 << pos)^num;}
ll geti() {ll x; read(x); return x;}

void read(int *aa, int sz) {fri(sz) scanf("%d", (aa + i));}
void read(ll *aa, int sz) {fri(sz) scanf("%lld", (aa + i));}
void read(ll *aa, int s, int e) {for (int i = s; i < s + e; i++)scanf("%lld", (aa + i));}
void read(int *aa, int s, int e) {for (int i = s; i < s + e; i++)scanf("%d", (aa + i));}
const ll mod =  1e9 + 7;
const ll N   =  1e6 + 10;
int dx[4] = { +0, +0, +1, -1};
int dy[4] = { -1, +1, +0, +0};

//......................___Start from here___.....................//
//......................_____________________....................//

ll dp[3005][3005];


int solve() {
	int n;
	read(n);
	vl arr(n);
	read(arr);
	arr.insert(arr.begin(), 0);
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i <= n - sz + 1; i++) {
			int j = i + sz - 1;
			dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
		}
	}

	cout << dp[1][n] << endl;





	return 0;
}


int main() {
#ifndef ONLINE_JUDGE
	input;
	output;
#endif
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	int cs = 1, cn = 1;
	// read(cs);
	while (cs--) {
		solve();

	}
}