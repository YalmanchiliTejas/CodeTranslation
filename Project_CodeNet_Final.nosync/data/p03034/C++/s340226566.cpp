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

ll n;
vl a;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	a=vl(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll res=0;
	vi b(n,1),c;
	for(int i=1;i<n;i++){
		ll tmp=0;
		b[0]=b[n-1]=0;
		for(int j=1;;j++){
			int I=j*i,J=n-I-1;
			if(I>=n||J<0||!b[I]||!b[J]||i>=J||I==J) break;
			tmp+=a[I]+a[J];
			b[I]=b[J]=0;
			c.push_back(I);
			c.push_back(J);
			res=max(res,tmp);
		}
		for(auto j:c) b[j]++;
		c.clear();
	}
	cout<<res<<endl;
}