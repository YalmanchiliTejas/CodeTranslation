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

int a[26];

int main(){
	a['y'-'a']++;
	a['h'-'a']++;
	a['n'-'a']++;
	a['u'-'a']++;
	a['j'-'a']++;
	a['m'-'a']++;
	a['i'-'a']++;
	a['k'-'a']++;
	a['o'-'a']++;
	a['l'-'a']++;
	a['p'-'a']++;
	while(1){
		string s;
		cin>>s;
		if(s=="#") break;
		int res=0,n=s.size();
		for(int i=0;i<n-1;i++) if(a[s[i]-'a']!=a[s[i+1]-'a']) res++;
		cout<<res<<endl;
	}
}
