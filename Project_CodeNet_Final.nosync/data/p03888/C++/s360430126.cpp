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
struct pos{
	int x,y,cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

ll gcd(ll a2,ll b2){
	int t;
	while(b2!=0){
		t=a2%b2;
		a2=b2;
		b2=t;
	}
	return a2;
}

ll lcm(ll a1,ll b1){
	if(a1*b1==0){return 0;}
	return (a1*b1/gcd(a1,b1));
}
int main() {

	int r1,r2;
	cin>>r1>>r2;
	int t=lcm(r1,r2)/r1+lcm(r1,r2)/r2;
	cout<<setprecision(12)<<double(lcm(r1,r2))/t<<endl;

	return 0;
}
