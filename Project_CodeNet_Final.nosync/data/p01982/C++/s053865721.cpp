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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-11;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main(){;
	while(1){
		int n,l,r;
		cin>>n>>l>>r;
		if(n==0) break;
		vi a(n);
		for(auto &i:a) cin>>i;
		int res=0;
		for(int i=l;i<=r;i++){
			bool B=0;
			for(int j=0;j<n;j++) if(i%a[j]==0){
				if(j%2==0) res++;
				B=1;
				break;
			}
			if(B==0&&n%2==0) res++;
		}
		cout<<res<<endl;
	}
}
