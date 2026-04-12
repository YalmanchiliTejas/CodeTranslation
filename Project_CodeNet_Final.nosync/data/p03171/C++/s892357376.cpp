#include <bits/stdc++.h>
   
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 1000000007
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define int long long
const int N=(int)3e3+5,INF=(int)-1e15;

int n,m;




int a[N];

int dp[N][N];


int solve(int l,int r)
{
  //  trace2(l,r);
    if(l>r)return 0;
    
    int &ans=dp[l][r];
    //cout<<dp[l][r]<<" ";
   // cout<<"h1\n";
    if(ans!=(-1000000000000000))return ans;
    
   
    int op1=a[l]-solve(l+1,r);
    int op2=a[r]-solve(l,r-1);
    
    return ans=max(op1,op2);
}


void solve()
{
    
    cin>>n;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1000000000000000;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    
    cout<<solve(1,n);
    
    
    
    
    
    
   
    
   
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--)solve();
	    
   
}
