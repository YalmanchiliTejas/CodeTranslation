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

	ll a,b,c,x,y;

	cin>>a>>b>>c>>x>>y;

	ll total=0;
	ll total2=10000000000;
	for(ll i=0; i<max(x,y)+1; i++){
		if(i<x){
			total+=(x-i)*a;
		}
		if(i<y){
			total+=(y-i)*b;
		}
		total2=min(total2,total);
		total=c*(i+1)*2;
	}
	cout<<total2<<endl;

	return 0;
}
