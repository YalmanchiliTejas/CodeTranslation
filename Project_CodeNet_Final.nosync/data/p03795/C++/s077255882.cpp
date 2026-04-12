// Think twice, Code once
// 1SAC
#include<bits/stdc++.h>
using namespace std;

/*============================ DEBUGGING =============================*/

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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

/*============================= DEFINES ==============================*/

#define eps 1e-9
#define mod 1000000007
#define pb emplace_back
#define mp make_pair
#define B begin()
#define E end()
#define F first
#define S second
#define tostr(x) to_string(x)
#define SZ(x) ((int)x.size())
#define ins insert
#define rep(i,x,y) for(int i=x;i<y;i++)
#define per(i,x,y) for(int i=x;i>y;i--)
#define repi(i,x,y) for(int i=x;i<=y;i++)
#define peri(i,x,y) for(int i=x;i>=y;i--)
#define inf (ll)LLONG_MAX
#define ds1(i,x) for(auto i=x.begin();i!=x.end();i++)
#define ds2(i,x) for(auto i:x)
#define FIO {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define dig(n) (int)(log10(n)+1)
#define ss(x,k) substr(x,k)  // x is the start pos and k is the length of substr.
#define set(x,k) memset(x,k,sizeof x)
#define Sort(a) sort(a.begin(),a.end())

/*============================== TYPEDEFS ============================*/

typedef long long ll;
typedef long double ld;
typedef long l;
typedef string str;
typedef vector<int> vi;
typedef vector<ll> vlli;
typedef vector<bool> vb;
typedef queue<int> qi;
typedef vector<pair<int,int> > vpii;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

/*============================ START FROM HERE =======================*/

int main(){
	FIO
	
	int n;cin>>n;
	cout<<800*n-(n/15)*200;
	return 0;
}
