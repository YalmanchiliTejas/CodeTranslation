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
	string s;
	while(cin>>s,s!="#"){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int n=1;
		rep(i,s.size())if(s[i]=='/')n++;
		vvi in(n);
		int t=0;
		rep(i,s.size()){
			if(s[i]=='/')t++;
			else{
				if(s[i]=='b')in[t].pb(1);
				else{
					rep(j,s[i]-'0')in[t].pb(0);
				}
			}
		}
		in[a-1][b-1]--;
		in[c-1][d-1]++;
		rep(i,n){
			int co=0;
			rep(j,in[i].size()){
				if(in[i][j]){
					if(co)cout<<co;
					cout<<"b";
					co=0;
				}else co++;
			}
			if(co)cout<<co;
			if(i!=n-1)cout<<"/";
		}
		cout<<endl;
	}
}