#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
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
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
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
//#define mt make_tuple
//typedef tuple<pii,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vi dp(1<<16,inf);
vp w;
int main(){
	int n;
	cin>>n;
	vp in(n);
	rep(i,n)cin>>in[i].first>>in[i].second;
	vs s(4);
	rep(i,4)cin>>s[i];
	char c[3]={'R','G','B'};
	rep(i,n)loop(j,-4,4)loop(k,-4,4)rep(l,3){
		int t=0,tt=0;
		rep(x,in[i].first)rep(y,in[i].second)if(0<=j+x&&0<=k+y&&j+x<4&&k+y<4){
			tt|=1<<((j+x)*4+k+y);
			if(s[j+x][k+y]==c[l])
				t|=1<<((j+x)*4+k+y);
		}
		w.pb({tt,t});
//		cout<<bitset<16>(t)<<" "<<bitset<16>(tt)<<endl;
	}
	dp[0]=0;
	queue<pii>que;
	que.push({0,0});
	while(que.size()){
		pii q=que.front();
		int a=q.first;
		que.pop();
		if(dp[a]<q.second)continue;
		rep(i,w.size()){
			int t=(a&(~w[i].first))|w[i].second;
			if(dp[t]>dp[a]+1){
				dp[t]=dp[a]+1;
				que.push({t,dp[t]});
			}
		}
	}
	cout<<dp[(1<<16)-1]<<endl;
}