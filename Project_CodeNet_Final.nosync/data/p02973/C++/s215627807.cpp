#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
const int mod = 1e9+7;
#define END {cout<<ans<<'\n'; return 0;}
#define ALL(v) (v).begin(),(v).end()
#define Pr(type) priority_queue<type>
#define gPr(type) priority_queue<type,vector<type>,greater<type>>
#define V(type) vector<type>
#define rep(i,n) for(int i=0; i<n; i++)
#define rer(i,st,en) for(int i=st; i<en; i++)
#define gnr(i,l,r) for(int i=int(r)-1; i>=int(l); i--)
#define eb emplace_back
#define pri1(a) cout<<(a)<<'\n'
#define pri2(a,n) rep(i,n-1)cout<<a[i]<<' '; cout<<a[n-1]<<'\n'
#define prip(p) cout<<p.first<<' '<<p.second<<'\n'
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n,m,_,x,y,q;
string s,sb;
bool ok;
char ch;

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(false);

  cin>>n; V(int)mi;
	V(int)::iterator it;
	rep(i,n){
		cin>>x; x*=-1;
		it=upper_bound(ALL(mi),x);
		if(it==mi.end())mi.eb(x);
		else{
			*it=x;
		}
	}
	pri1(mi.size());
}