#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-11;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		string s;
		cin>>s;
		if(s=="#") break;
		int h=1,w;
		for(auto c:s) if(c=='/') h++;
		vvi a(h,vi(11));
		s+='/';
		int id=0;
		string t;
		for(auto c:s){
			if(c=='/'){
				int x=0;
				for(auto c1:t){
					if(c1=='b') a[id][x++]++;
					else x+=c1-'0';
				}
				w=x;
				t="";
				id++;
			}
			else t+=c;
		}
		int x,y,X,Y;
		cin>>x>>y>>X>>Y;
		a[x-1][y-1]--;
		a[X-1][Y-1]++;
		t="";
		for(int i=0;i<h;i++){
			if(i) t+='/';
			int cnt=0;
			for(int j=0;j<w;j++){
				if(a[i][j]){
					if(cnt) t+=(char)('0'+cnt);
					t+='b',cnt=0;
				}
				else cnt++;
			}
			if(cnt) t+=(char)('0'+cnt);
		}
		cout<<t<<endl;
	}
}
