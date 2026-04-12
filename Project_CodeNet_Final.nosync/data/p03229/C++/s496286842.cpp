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
	ll total1=0,total2=0;

	cin>>n;

	for(int i=0; i<n; ++i){
		cin>>a[i];
	}


	sort(a, a + n, greater<ll>());

	if(n%2==0){
		for(int i=0; i<n/2; ++i){
			total1+=a[i]*2;
		}
		for(int j=n/2; j<n; ++j){
			total1-=a[j]*2;
		}
		total1=total1-a[n/2-1]+a[n/2];
	}

	if(n%2>0){
		for(int i=0; i<n/2+1; ++i){
			total1+=a[i]*2;
		}
		for(int j=n/2+1; j<n; ++j){
			total1-=a[j]*2;
		}
		total1=total1-a[n/2]-a[n/2-1];
		for(int i=0; i<n/2; ++i){
			total2+=a[i]*2;
		}
		for(int j=n/2; j<n; ++j){
			total2-=a[j]*2;
		}
		total2=total2+a[n/2]+a[n/2+1];

		total1=max(total1,total2);
	}

	cout<<total1<<endl;

	return 0;

}
