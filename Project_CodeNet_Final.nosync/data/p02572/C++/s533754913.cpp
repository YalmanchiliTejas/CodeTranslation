#include<bits/stdc++.h>
using namespace std;

//highlight color RGB = [70,70,70]
#define asll unsigned long long
#define ll long long
#define ld long double
#define imt int
#define pii pair<int,int>
#define st first
#define nd second
#define kj <<" "<<
#define kjb <<" ";
#define dg <<","<<
#define ml <<endl;
#define co cout<<
#define ter cout<<endl;
#define sibi cout<<"TES"<<endl;
#define tes(x) cout<<"TES "<<x<<endl;
#define psbk(x) push_back(x);
#define For(x,a,b) for(int x=(a);x<(b);x++)
#define FOR(x,n) for(int x=0;x<(n);x++)
#define kera(x,m) for( int i = 0;i < m ; i++ ){ cout<<"x["<< i <<"] =" kj x[i] ml}
#define kpr(x) cout<<"("<<x.st dg x.nd <<")" ml
#define kkor(p) cout<<"("<<p.x dg p.y <<")" ml
#define m_p make_pair
asll M=1e9+7;
int n,m,tc;
int p,q,r;
ll ps[200005];
ll a[200005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(0);
	srand(time(0));
	cin>>n;
	ps[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ps[i]=ps[i-1]+a[i];
		ps[i]=ps[i]%M;
	}
	ll hasil=0;
	ll js;
	for(int i=1;i<=n;i++){
		int j=i+1;
		js=a[j]*ps[i];
		js%=M;
		hasil+=js;
		hasil%=M;
	}
	cout<<hasil<<endl;
	
}
