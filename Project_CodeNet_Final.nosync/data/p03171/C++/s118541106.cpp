//killer_R@$tog!
#include<bits/stdc++.h>
using namespace std;
#define hell 1000000007
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)
#define mp make_pair
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define ll long long int
#define N 100009
#define all(b) b.begin(),b.end()
#define sz sizeof
#define shuru(h) memset(h,0,sz(h))
//int pr[N];
//int seg[N];
/*int query(int l,int r,int sl,int sr,int p)
{
    if(r<sl || l>sr)
        return 0;
    if(sr<=r && sl>=l)
        return seg[p];
    int m=sl+(sr-sl)/2;
    return (__gcd(query(l,r,sl,m,2*p+1),query(l,r,m+1,sr,2*p+2)));
}

int build(int l,int r,int p,int arr[])
{
    if(l==r)
    {
        seg[p]=arr[l];
        return seg[p];
    }
    int m=l+(r-l)/2;
    seg[p]=__gcd(build(l,m,2*p+1,arr),build(m+1,r,2*p+2,arr));
    return seg[p];
}
void isprime()
{
    memset(pr,1,sizeof(pr));
    pr[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(pr[i])
        {
            for(j=i*i;j<=N;j+=i)
            {
                pr[j]=0;
            }
        }
    }
}*/
void killer()
{
    int n;cin>>n;
    ll a[n+1],dp[n+1][n+1];shuru(dp);
    rep(i,1,n+1)
    {
        cin>>a[i];
        dp[1][i]=a[i];
    }
    rep(i,2,n+1)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            int t=j+i-1;
            dp[i][j]=max(a[j]-(dp[i-1][j+1]),a[t]-(dp[i-1][j]));
        }
    }
    cout<<dp[n][1];
    return;
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    //int h=(int)ceil(log2(n));
    //h=2*(int)pow(2,h)-1;
    //build(0,n-1,0,a);

    ll t;
    t=1;
    while(t--)
        killer();

    return 0;
}