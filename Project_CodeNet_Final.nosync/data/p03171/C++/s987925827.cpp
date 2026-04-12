// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())printf("%d ",v[_]);cout<<endl;}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
// int dx[]={0,1,0,-1};
// int dy[]={1,0,-1,0};//RDLU
#define yes puts("YES")
#define no puts("NO")

int n;
vi in;
int dp[3010][3010][2];
int f(int l,int r,int a){
	if(l>r)return 0;
	if(dp[l][r][a]-inf)return dp[l][r][a];
	int t1=f(l+1,r,a^1)+(a?-in[l]:in[l]);
	int t2=f(l,r-1,a^1)+(a?-in[r]:in[r]);
	if(a)return dp[l][r][a]=min(t1,t2);
	else return dp[l][r][a]=max(t1,t2);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	in=vi(n);
	rep(i,n)cin>>in[i];
	rep(i,3010)rep(j,3010)rep(k,2)
		dp[i][j][k]=inf;
	cout<<f(0,n-1,0)<<endl;

}
