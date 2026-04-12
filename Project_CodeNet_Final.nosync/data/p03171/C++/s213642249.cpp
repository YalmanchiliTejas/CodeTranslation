#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
//#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
// cerr<<1.0/CLOCKS_PER_SEC<<endl;
using namespace std;
#define N  1000000007 
#define MAXN   200005
//ll int dp[1001][100005];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cout.precision(15);
ll int n,i,j;
cin>>n;
vi a(n);
ll int sum=0;
rep(i,0,n)
{cin>>a[i];
sum+=a[i];}
ll int dp[n][n];
rep(i,0,n)
rep(j,0,n)
dp[i][j]=0;
rep(g,0,n)
{for(i=0,j=g;j<n;i++,j++)
{
if(i==j)
dp[i][j]=a[i];
else if(j==i+1)
	dp[i][j]=max(a[i],a[j]);
else
{
ll int x,y,z;
if(j>=i+2)
x=dp[i+2][j];
else
x=0;	
if(j-1>=i+1)
y=dp[i+1][j-1];
else
y=0;
if(j-2>=i)
z=dp[i][j-2];
else
z=0;
dp[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
}
}}
cout<<2*dp[0][n-1]-sum;
}
