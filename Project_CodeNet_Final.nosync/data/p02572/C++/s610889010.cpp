#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
#include <unordered_set> 

//#include <bits/stdc++.h>
using namespace std;
#define speedio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

#define ll         long long
#define int        long long
#define pb         push_back
#define ff         first
#define sec        second
#define eb         emplace_back
#define SORT(a)      sort(a.begin(),a.end())
#define SORTR(a)     sort(a.rbegin(),a.rend())
#define all(x)       x.begin(),x.end()
#define sz(v)        ((int)(v.size()))
#define mem(a,val)   memset(&a,val,sizeof(a))
#define mid(s,e)     ((s)+((e)-(s))/2)
#define endl       '\n'


typedef vector<int>     vi;
typedef vector<bool>    vb;
typedef vector<vi>      vvi;
typedef vector<string>  vs;

typedef pair<int, int>  pii;
typedef vector< pii >   vpii;
typedef vector< vpii >  vvpii;

#define fo(i,a,b)     for(ll i = (int)(a); i <= (int)(b); ++i)
#define fr(i,b)       for(ll i = (int)0; i < (int)(b); ++i)
#define rf(i,a,b)     for(ll i = (ll)(a); i >= (ll)(b); --i)
#define read(a,n)     for(int i=0;i<n;++i)cin>>a[i];
#define show(a,n)     for(int i=0;i<n;++i)cout<<a[i]<<' ';cout<<endl;

template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout << "\n"; }

const int MOD = 1e9 + 7 ;
const int INF = 1e18    ;


void add(ll &x, ll y) { x += y; if (x >= MOD) x -= MOD; if (x < 0) x += MOD; }
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;




void solve() {


	int n; rd(n); 
	vi a(n); read(a,n); 

	vi prf(n,0); 

	for(int i=0 ;i<n ; ++i ) {
		prf[i]=(((i==0)?0:prf[i-1])+a[i]); 
	}
	
	int ans=0; 

	for(int i=0 ;i<n ; ++i ){ 
		ans=(ans + (a[i]*((prf[n-1]-prf[i])%MOD))%MOD)%MOD; 
	}

	pp(ans); 

}


int32_t main() {
  speedio; cout << fixed << setprecision(12);
/*#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif*/

  int T = 1; //cin>>T;
  while (T--) {
    solve();
  }

  return 0;
}





