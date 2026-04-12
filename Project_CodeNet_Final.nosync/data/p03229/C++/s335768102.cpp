#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};


int main() {

	ll n;
	ll a[100001];
	ll c[100001]={};
	ll d[100001]={};
	ll o=0,o2=0;
	ll total=0;

	cin>>n;

	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	sort(a, a + n, greater<ll>());

	if(n%2==0){
		for(int j=0; j<n/2; ++j){
			o+=a[j]*2;
		}
		for(int k=n/2; k<n; ++k){
			o-=a[k]*2;
		}
		o=o-a[n/2-1]+a[n/2];
	}
	if(n%2>0){
		for(int j=0; j<n/2; ++j){
			o+=a[j]*2;
		}
		for(int k=n/2; k<n; ++k){
			o-=a[k]*2;
		}
		o=o+a[n/2]+a[n/2+1];
		for(int j=0; j<n/2+1; ++j){
			o2+=a[j]*2;
		}
		for(int k=n/2+1; k<n; ++k){
			o2-=a[k]*2;
		}
		o2=o2-a[n/2-1]-a[n/2];
		o=max(o,o2);
	}
	cout<<o<<endl;

	return 0;

}
