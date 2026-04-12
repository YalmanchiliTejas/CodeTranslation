/*

                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    prayer
*/

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
#define show1d(v) rep(_,v.size())cout<<" "<<v[_];cout<<endl;
#define show2d(v) rep(__,v.size()){rep(_,v[__].size())cout<<" "<<v[__][_];cout<<endl;}
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
// #define mt make_tuple
// typedef tuple<int,int,int> tp;
// typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
//nCr mod m
int MOD;
#define M 3100
vector<ll> fact;
bool h=false;
void init(){
	h=true;
	fact=vector<ll>(M);
	fact[0]=fact[1]=1;
	loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// a^b mod MOD
ll powmod(ll a,ll b,ll m=MOD){
	ll out=1;
	ll p=a%m;
	while(b){
		if(b&1)out=out*p%m;
		p=p*p%m;
		b>>=1;
	}
	return out;
}
//nCr
ll nCr(ll n,ll r,ll m=MOD){
	if(!h)init();
	if(n<0||r<0||n<r)return 1;//??????
	ll out=fact[n]*powmod(fact[r]*fact[n-r]%m,m-2,m)%m;
	return out;
}
int star[M][M];
signed main(){
	int n;
	cin>>n>>MOD;
	star[0][0]=1;
	loop(i,1,M)loop(j,1,i+1)star[i][j]=(star[i-1][j-1]+j*star[i-1][j]%MOD)%MOD;
	
	int out=0;
	rep(i,n+1){
		int sum=0;
		rep(j,i+1)(sum+=star[i+1][j+1]*powmod(2,(n-i)*j%MOD))%=MOD;
		(out+=(MOD+(i%2?-1:1)*(nCr(n,i)*sum%MOD*powmod(2,powmod(2,n-i,MOD-1))%MOD))%MOD)%=MOD;
	}
	cout<<out<<endl;
}













