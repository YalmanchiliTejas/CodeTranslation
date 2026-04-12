#include <bits/stdc++.h>
using namespace std;

/*iamsorry*/
 
#define thegamebegins   ios_base::sync_with_stdio(false); cin.tie(nullptr); //cout.tie(nullptr);
#define fileio          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define int             long long
#define float           long double
#define E               "\n"
#define S               " "
#define INF             9e18
#define M7              1000000007
#define M9              998244353
#define PI              3.141592653589793238L
#define lcm(a,b)        ((a)/__gcd((a),(b)))*(b)
#define midl(l,r)       ((l)+((r)-(l))/2)
#define prec(n)         fixed<<setprecision(n)
#define in(arr,n)       for(int i=0; i<(n); ++i) cin>>arr[i]
#define fi(i,x,y)       for(int i=(x); i<(y); ++i)
#define fb(i,x,y)       for(int i=(x); i>=(y); --i)
#define fa(i,s)         for(auto i:(s))
#define fp(i,s)         for(auto i=(s).begin(); i!=(s).end(); ++i)
#define pf(i,s)         for(auto i=(s).rbegin(); i!=(s).rend(); ++i)
#define all(s)          (s).begin(), (s).end()
#define rev(s)          (s).rbegin(), (s).rend()
#define vc              vector
#define fr              first
#define sc              second
#define pb              push_back
#define eb              emplace_back
#define ins             insert
#define emp             emplace

#ifdef DOPPELLEBEN
template<typename T1,typename T2> ostream& operator<<(ostream &out,const pair<T1,T2> &p) {return out<<'('<<p.first<<", "<<p.second<<')';}
template<typename T> auto operator<<(ostream &out,T &&x)->decltype(x.begin(),out) {out<<'{'; for(auto it=x.begin();it!=x.end();++it)out<<*it<<(it==prev(x.end())?"":", "); return out<<'}';}
void dump() {}
template<typename T,typename... Args> void dump(T &&x,Args... args) {cerr<<" "<<x; dump(args...);}
struct ND{~ND(){cerr<<"]\n";}};
#define dbg(x...) cerr<<" ["<<(strcmp(#x,"")?#x ":":""),dump(x),ND(),cerr<<""
#else
#define dbg(...) 0 && cerr
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rann(n) rng()%(n)
#define ran(l,r) (l)+rng()%((r)-(l)+1)

template<typename T,typename t> T maxm(T &x,t y) {if(y>x)x=y; return x;}
template<typename T,typename t> T minm(T &x,t y) {if(y<x)x=y; return x;}
template<typename T> int sz(T &&x) {return (int)((x).size());}

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int,int>;
using mii = map<int,int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int,int>>;
using seti = set<int>;
using setd = set<int,greater<int>>;
using pqmx = priority_queue<int>;
using pqmn = priority_queue<int,vector<int>,greater<int>>;

/*__*/

void Main() {
	int t; cin>>t;
	cout<<(t>=30?"Yes":"No");
}

signed main() {
    thegamebegins

    int T=1;
    // cin>>T;
    while(T--) Main();

    return 0;
}