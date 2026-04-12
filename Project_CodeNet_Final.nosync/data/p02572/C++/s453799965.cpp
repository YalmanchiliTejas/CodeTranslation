#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <assert.h>
#include <sstream>
#include <type_traits>
#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pF first
#define pS second
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define GCD(a,b) __gcd((a),(b))
#define dbl(x) (double)(x)
#define vi vector <int>
#define vii vector < pair <int, int> >
#define vll vector <long long>
#define allof(x) (x).begin(), (x).end()
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

vector<string>vec_splitter(string s){s+=',';vector<string>res;while(!s.empty()){res.push_back(s.substr(0,s.find(',')));s=s.substr(s.find(',')+1);}
return res;}
void debug_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM){cerr<<endl;}
template<typename Head,typename...Tail>void debug_out(vector<string>args,int idx,int LINE_NUM,Head H,Tail...T){if(idx>0)cerr<<", ";else cerr<<"Line("<<LINE_NUM<<") ";stringstream ss;ss<<H;cerr<<args[idx]<<" = "<<ss.str();debug_out(args,idx+1,LINE_NUM,T...);}
#ifdef LOCAL_DBG
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int main () {
	fastCin;
	int n;
	cin >> n;
	ll a[200005] = {0}, s[200005] = {0};
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
	}
	s[n] = a[n];
	for (int x = n-1; x >= 1; x--) {
		s[x] = a[x] + s[x+1];
	}
	ll ans = 0, mod = 1e9+7;
	for (int x = 1; x <= n-1; x++) {
		ans += (a[x] * (s[x+1]%mod))%mod;
		ans %= mod;
	}
	cout << ans << "\n";
	return 0;
}