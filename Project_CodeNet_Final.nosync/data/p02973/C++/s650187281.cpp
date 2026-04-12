#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vi a;

int main(){
	cin>>n;
	a=vi(n);
	for(auto &i:a) cin>>i;
	reverse(a.begin(),a.end());
	vi dp(n+1,inf);
	for(auto i:a){
		int id=upper_bound(dp.begin(),dp.end(),i)-dp.begin();
		dp[id]=i;
	}
	cout<<lower_bound(dp.begin(),dp.end(),inf)-dp.begin()<<endl;
}