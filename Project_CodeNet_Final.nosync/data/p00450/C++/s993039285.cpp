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
const int inf=1<<30;
int main(){
	int n;
	while(cin>>n,n){
		int a;
		cin>>a;
		vp in;
		in.pb(pii(a,1));
		rep(i,n-1){
			cin>>a;
			int s=in.size();
			if(i%2||in[s-1].first==a){
				if(in[s-1].first==a)in[s-1].second++;
				else in.pb(pii(a,1));
			}else{
				in[s-1].first^=1;
				in[s-1].second++;
				if(s>1){
					in[s-2].second+=in[s-1].second;
					in.erase(in.begin()+s-1);
				}
			}
		}
		int co=0;
		rep(i,in.size())if(!in[i].first)co+=in[i].second;
		cout<<co<<endl;
	}
}