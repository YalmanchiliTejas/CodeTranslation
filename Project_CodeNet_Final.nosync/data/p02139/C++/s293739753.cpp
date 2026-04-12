#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def>pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<string> vs;
Def inf=1000000019;
int main(){
	ll n,m;
	cin>>n>>m;
	ll t=0;
	while(m--){
		ll a,b;
		cin>>a>>b;
		if(a){
			t+=b;
		}else{
			cout<<(t+b-1)%n+1<<endl;
		}
	}
}








