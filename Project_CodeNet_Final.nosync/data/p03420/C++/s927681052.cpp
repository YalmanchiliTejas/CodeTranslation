#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define EPS (1e-7)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};

int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int MAX=1e9;

int main(){
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	if(k==0){
		ans=n*n;
		cout<<ans<<endl;
		return 0;
	}
	//a<b
	for(ll a=k;a<=n;a++){
		ans+=(n-a);
	}
	//a>b
	for(ll b=k+1;b<=n;b++){
		ll i=1;
		while(b*i+b-1<=n){
			ans+=(b-k);
			i++;
		}
		if(n>=b*i+k){
			ans+=n-b*i-k+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}