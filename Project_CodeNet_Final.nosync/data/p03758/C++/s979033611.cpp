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
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;

int main(){
	cin>>n;
	vp a;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
		string s(n,'0');
		s[i]=s[j]='1';
		cout<<"? "<<s<<endl;
		int t;
		cin>>t;
		if(t==1) a.push_back({i,j});
	}
	cout<<'!';
	for(int i=0;i<n-1;i++){
		cout<<' '<<'('<<a[i].first<<','<<a[i].second<<')';
	}
	cout<<endl;
}