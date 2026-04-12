#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
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
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

const int M=40;
ll n,x,m;
vvl a,b;

int main(){
	cin>>n>>x>>m;
	a=b=vvl(M,vl(m));
	for(ll i=0;i<m;i++){
		a[0][i]=i;
		b[0][i]=i*i%m;
	}
	for(int i=1;i<M;i++) for(int j=0;j<m;j++){
		b[i][j]=b[i-1][b[i-1][j]];
		a[i][j]=a[i-1][j]+a[i-1][b[i-1][j]];
	}
	ll res=0;
	for(int i=0;i<M;i++) if(n&1LL<<i){
		res+=a[i][x];
		x=b[i][x];
	}
	cout<<res<<endl;
}