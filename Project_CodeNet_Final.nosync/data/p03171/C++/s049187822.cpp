// code.begin();
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back 
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
#define print(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define my_time ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long 
#define endl "\n"
#define MOD 1000000007
const long long int INF=1e18;
#define mod 1000000007
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    ordered_set; 
//find_by_order(x)
//order_of_key(x)  


int power(int x,unsigned int y)
{
    int res=1;
    
    while(y>0)
    {
        // if y is odd multiply with result
        if(y&1)
        res=res*x;
        
        y=y>>1; // y=y/2;
        x=x*x;
        
    }
    return res;
}

int gcd(int a,int b)
{
    if(b==0)
    return a;
    
    return gcd(b,a%b);
}

ll  max3(ll  a, ll  b, ll c)
{
    return max(c, max(a, b));
}
int min3(int a, int  b, int  c)
{
    return min(a, min(b, c));
}

int  powermod(int  x, int  y, int p )
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
int logg(int  a)
{
    int  x = 0;
    while (a > 1)
    {
        x++;
        a /= 2;
    }
    return x;
}


int modinv(int x)
{
    return powermod(x, mod - 2, mod);
}


int  main(){
	my_time;

int t;
t=1;
//cin>>t;int test=0;
while(t--)
{
int n;
cin>>n;
int arr[n];ll sum=0;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
    sum+=arr[i];
}
ll dp[n+5][n+5][2];
for(int i=0;i<n;i++)
{
    dp[i][i][0]=arr[i];
    dp[i][i][1]=0;
}
for(int i=1;i<n;i++)
{
    for(int j=0;j+i<n;j++)
    {
        int l=j;int r=j+i;
        dp[l][r][0]=max(arr[l]+dp[l+1][r][1],arr[r]+dp[l][r-1][1]);
        dp[l][r][1]=min(dp[l+1][r][0],dp[l][r-1][0]);
    }
}

ll ans=2*dp[0][n-1][0]-sum;

cout<<ans<<endl;


}
    return 0;
}


//code.end();



