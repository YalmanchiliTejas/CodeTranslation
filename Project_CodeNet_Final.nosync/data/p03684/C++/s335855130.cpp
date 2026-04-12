#include <bits/stdc++.h>
using namespace std;
#define printvector(v,n) for(int i=1;i<=n;i++) cout<<v[i]<<" "; cout<<ln;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for int64)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define RFOR(i,b,a) for(int i=b; i>=a; i--)
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setPresent(x,s) (s.find(x)!=s.end())
#define flush() fflush(stdout)
typedef long long int64;
typedef pair<int,int> p32;
typedef pair<int64,int64> p64;
typedef pair<double,double> pdd;
typedef vector<int64> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
template<class T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
const int lim=1e5+5;
int64 x,y,n,t,p[lim],c[lim];
vp64 vx,vy;
vector<pair<int64,p64> > e;

int64 find(int64 x){
	return p[x]==x ? x : find(p[x]); 
}
void unite(int64 a,int64 b){
	a=find(a);b=find(b);
	if(c[a]<c[b]) swap(a,b);
	p[b]=a; c[a]+=c[b];	
}
int main(){
	cin>>n;
	FOR(i,1,n) p[i]=i;
	FOR(i,1,n) c[i]=1;
	FOR(i,1,n){
		cin>>x>>y;
		vx.pb(mp(x,i)); vy.pb(mp(y,i));
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	FOR(i,0,n-2){
		e.pb(mp(abs(vx[i].fi-vx[i+1].fi),mp(vx[i].se,vx[i+1].se)));
	}
	FOR(i,0,n-2){
		e.pb(mp(abs(vy[i].fi-vy[i+1].fi),mp(vy[i].se,vy[i+1].se)));
	}
	sort(e.begin(),e.end());
	for(auto & ed:e){
		if(find(ed.se.fi)!=find(ed.se.se)){
			unite(ed.se.fi,ed.se.se);
			t+=ed.fi;
		} 	
	}
	cout<<t<<endl;
}
