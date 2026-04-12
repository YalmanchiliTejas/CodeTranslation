#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define pb(x)           push_back(x)
#define mkp(x,y)        make_pair(x,y)
#define L               length()
#define int             long long
#define bs              binary_search
#define mod             1e9+7
#define IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define F               first
#define S               second
#define pii             pair<int,int>
#define vi              vector<int>
#define vs              size()
#define gcd(a,b)        __ gcd(a,b)
#define endl            '\n'
#define atoi            stoi
#define elasped_time    1.0 * clock() / CLOCKS_PER_SEC
#define si              set <int>
#define vpii            vector < pair <int,int> >
#define memf(a)         memset(a,false,sizeof(a))
#define memt(a)         memset(a,true,sizeof(a))
#define xxx             998244353
#define pi              3.141592653589
#define ninf            INT_MIN
#define inf             INT_MAX
#define sz(v)           ((int)(v).size())
#define rep(i,a,b)      for(int i=a;i<=b;i++)
int max(int a,int b){if(a>b){return a;}else{return b;}}
int min(int a,int b){if(a<b){return a;}else{return b;}}
int power(int b,int e)
{
    if(e==0)
    return 1;
    if(e%2)
    return ((b*power((b)*(b),(e-1)/2)));
    else
    return power((b)*(b),e/2);
}
int modpower(int b,int e,int q)
{
    int MOD=q;
    if(e==0)
    return 1;
    if(e%2)
    return ((b%MOD)*modpower((b%MOD)*(b%MOD),(e-1)/2,q))%MOD;
    else
    return modpower((b%MOD)*(b%MOD),e/2,q)%MOD;
}
void dpv(vi v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void dpv(vpii v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i].F<<" "<<v[i].S<<endl;
    }
}
void dpv(set <int> v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
//////////////////////**TREE MOVES STARTS**//////////////////////////////
///// **TREE MOVES ENDS**////////////////////////////

////*SOLUTION TO THE QUESTION STARTS HERE*///////
int md=mod;
void oblivious()
{
    int n;
    cin>>n;
    int a[n];
    int pref[n+1];
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    pref[0]=0;
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+a[i-1];
    }
    for(int i=0;i<n;i++)
    {
        int k=(sum-pref[i+1])%md;
        int k1=a[i]%md;
        ans=((k*k1)%md+ans%md)%md;
    }
    cout<<ans<<endl;
}
signed main()
{
    IOS;
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int t=1;
    //cin>>t;
    //int z=t;
    while(t--)
    {
        //cout<<"Case #"<<(z-t)<<": ";
        oblivious();
    }
    return 0;
}
//Editorial
/*

    */