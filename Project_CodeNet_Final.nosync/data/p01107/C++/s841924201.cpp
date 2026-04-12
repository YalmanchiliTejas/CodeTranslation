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
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
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
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};//RBLF
int main(){
	int n,m;
	while(cin>>n>>m,n){
		vs in(n+2,string(m+2,'#'));
		rep(i,n){
			string s;
			cin>>s;
			in[i+1]="#"+s+"#";
		}
		vvi used(n+2,vi(m+2));
		int x=1,y=1,to=1;
		int cnt=1;
		do{
			int nto=(to+1)%4;
			rep(i,4){
				int nx=x+dx[nto];
				int ny=y+dy[nto];
				if(in[nx][ny]!='#'){
					if(used[nx][ny]==0){
						x=nx;y=ny;to=nto;
						used[nx][ny]=cnt++;
						goto end;
					}else if(cnt==used[nx][ny]+2){
						used[x][y]=0;
						in[x][y]='#';
						x=nx;y=ny;to=nto;
						cnt--;
						goto end;
					}
				}
				nto=(nto+3)%4;
			}
//			cout<<x<<" "<<y<<endl;
			break;
			end:;
//			show2d(used);
		}while(!(x==1&&y==1));
		
		if(used[1][1]&&used[1][m]&&used[n][1]&&used[n][m])
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}










