/*

    author : s@if

*/

#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define fi first
#define sec second
#define MAX INT_MAX
#define INF 99999999
#define ll long long
#define PI acos(-1.0)
#define MOD 1000000007
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define ull unsigned long long
#define triplell pair<pair<ll,ll> , ll>
#define triple pair<pair<int,int> , int>
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Forn(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define forba(i,a,b) for(int i=(int)b;i>=(int)a;i--)

int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hr[]={-2,-2,-1,+1,+2,+2,-1,+1};
int hc[]={+1,-1,+2,+2,-1,+1,-2,-2};

const int MAXN = (int)1e5+9;

int main()
{
/*	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);  */
    
    int i,j,k,l,m,n,p,q,x,y,u,v,r,tc,t;
    
    cin>>n;
    int ara[n+9];
    
    for(i=1;i<=n;i++)
    {
    	cin>>ara[i];
	}
	
	int ans = 1;
	int mx = ara[1];
	
	for(i=2;i<=n;i++)
	{
		if(ara[i]>=mx)
		{
			ans++;
			mx = ara[i];
		}
	}
	
	cout<<ans<<endl;
	
//	main();

    return 0;
}