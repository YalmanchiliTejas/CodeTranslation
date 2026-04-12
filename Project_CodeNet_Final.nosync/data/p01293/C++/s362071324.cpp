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
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int main(){
	char c;
	map<char,int>m;
	m['C']=0;
	m['D']=1;
	m['H']=2;
	m['S']=3;
	m['T']=10;
	m['J']=11;
	m['Q']=12;
	m['K']=13;
	m['A']=14;

	while(cin>>c,c!='#'){
		vvp in(13,vp(4));
		int ns=0,ew=0;
		rep(i,4)rep(j,13){
			char a,b;
			cin>>a>>b;
			if(isdigit(a))in[j][i]=pii(m[b]+(b==c?20:0),a-'0');
			else in[j][i]=pii(m[b]+(b==c?20:0),m[a]);
		}
		int co=0;
		int p=0;
		rep(i,13){
			vip t(4);
			rep(j,4)t[j]=pip(in[i][j].first,pii(in[i][j].second,j));
			rep(j,4)if(in[i][p].first==in[i][j].first)t[j].first+=10;
			sort(all(t));
			if(t[3].second.second%2==0)ns++;
			else ew++;
			p=t[3].second.second;
//			cout<<p<<endl;
		}
		if(ew>ns)cout<<"EW "<<ew-6<<endl;
		else cout<<"NS "<<ns-6<<endl;
	}
}