#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"
#define mod 1000000007

ll w,e;
int main(void)
{
	CIN;
	int tc,l,k=0,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	int a,b,c;
	cin>>a>>b>>c>>x>>y;
	cout<<min(a*x+b*y,min(2*c*x+b*max(y-x,0),2*c*y+a*max(x-y,0)));

}