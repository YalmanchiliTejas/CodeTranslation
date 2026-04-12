#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bang_bang ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cases int t;cin>>t;while(t--)
#define pb push_back
#define ppb pop_back
#define mem(x,a) memset(x,a,sizeof(x));
#define ld long double
#define mp make_pair
#define limit 200005
#define inf 1e18
const int md = 998244353;

int movesx[3]={-1,0,1};
int movesy[3]={-1,0,1};

int moves[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


bool cmp(int a,int b)
{
	return a>b;
}

int gcd(int a, int b){return b?gcd(b,a%b):a;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int power(int base,int exponent,int mod=inf)
{
    if(exponent==0)
        return 1;
    int temp=power(base,exponent/2,mod);
    temp=(temp*temp)%mod;
    if(exponent%2!=0)
    {
        temp=(temp*base)%mod;
        return temp;
    }
    return temp;
}

int ncr(int a,int b)
{
    int dp[b+1];
    mem(dp,0)
    dp[0]=1;
    for(int i=1;i<=a;i++)
        for(int j=min(i,b);j>0;j--)
            dp[j]=(dp[j]+dp[j-1])%md;
            //C(n,r)=C(n-1,r-1)+C(n-1,r)
    return dp[b];
}
int n,t;
float p;


signed main(){
    bang_bang
    //cases
    {
        int n;
        cin>>n;
        if(n>=30) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}