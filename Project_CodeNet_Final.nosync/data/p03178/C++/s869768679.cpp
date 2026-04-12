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

int dp[10010][110][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int d;
	cin>>s>>d;
	int MOD=1000000007;
	rep(i,10010)rep(j,110)rep(k,2)dp[i][j][k]=0;
	dp[0][0][0]=1;
	rep(i,s.size())rep(j,d)rep(k,2)rep(x,10){
		int I=i+1,J=(j+x)%d,K=k|(s[i]-'0'>x);
		if(!k&&s[i]-'0'<x)continue;
		(dp[I][J][K]+=dp[i][j][k])%=MOD;
	}
	cout<<(MOD-1+dp[s.size()][0][0]+dp[s.size()][0][1])%MOD<<endl;
}
