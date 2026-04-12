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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

const int M=100;
int A,B,b[M+1][M+1];
vvi a;

int main(){
	cin>>A>>B;
	a=vvi(A+1,vi(B+1));
	for(int i=1;i<=A;i++) for(int j=1;j<=B;j++) cin>>a[i][j];
	for(int i=0;i<=M;i++) for(int j=0;j<=M;j++){
		int res=0;
		for(int k=1;k<=A;k++) for(int l=1;l<=B;l++) res=max(res,a[k][l]-k*i-l*j);
		b[i][j]=res;
	}
	bool flag=1;
	for(int i=1;i<=A;i++) for(int j=1;j<=B;j++){
		bool BB=0;
		for(int k=0;k<=M;k++) for(int l=0;l<=M;l++) if(b[k][l]+k*i+l*j==a[i][j]) BB=1;
		flag&=BB;
	}
	if(flag){
		cout<<"Possible"<<endl;
		cout<<2*M+2<<' '<<2*M+(M+1)*(M+1)<<endl;
		for(int i=1;i<=M;i++) cout<<i<<' '<<i+1<<" X"<<endl;
		for(int i=M+2;i<2*M+2;i++) cout<<i<<' '<<i+1<<" Y"<<endl;
		for(int i=0;i<=M;i++) for(int j=0;j<=M;j++) cout<<i+1<<' '<<2*M+2-j<<' '<<b[i][j]<<endl;
		cout<<1<<' '<<2*M+2<<endl;
	}
	else cout<<"Impossible"<<endl;
}