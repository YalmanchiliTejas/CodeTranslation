// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
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
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int n,m;
	cin>>n>>m;
	vvi in(n,vi(m));
	rep(i,n)rep(j,m)cin>>in[i][j];
	vvi c(110,vi(110));
	rep(i,110)rep(j,110){
		int ma=0;
		rep(k,n)rep(l,m)ma=max(ma,in[k][l]-i*(k+1)-j*(l+1));
		c[i][109-j]=ma;
	}
	bool h=true;
	rep(i,n)rep(j,m){
		int mi=inf;
		rep(k,110)rep(l,110)mi=min(mi,(i+1)*k+(j+1)*l+c[k][109-l]);
		if(mi!=in[i][j])h=false;
	}
	
	if(!h)cout<<"Impossible"<<endl;
	else{
		cout<<"Possible"<<endl;
		cout<<"220 "<<218+110*110<<endl;
		rep(i,109)cout<<1+i<<" "<<2+i<<" X"<<endl;
		rep(i,109)cout<<219-i<<" "<<220-i<<" Y"<<endl;
		rep(i,110)rep(j,110){
			cout<<1+i<<" "<<111+j<<" "<<c[i][j]<<endl;
		}
		cout<<"1 220"<<endl;
	}
}







