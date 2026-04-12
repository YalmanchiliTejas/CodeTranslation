#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define mp make_pair
int main()
{
	int i,j,k,r,g,b;
	sd(r);
	sd(g);
	sd(b);
	int temp=r*100+g*10+b;
	printf("%s\n",(temp%4 == 0 )? "YES":"NO" );
	return 0;
}