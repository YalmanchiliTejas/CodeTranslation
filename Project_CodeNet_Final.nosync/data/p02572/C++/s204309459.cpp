#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector <int>
#define ff first
#define ss second
#define vp vector <pair<int,int>>
#define vpp vector <pair<int,pair<int,int>>>
#define seti set<int>
#define setbit(x) __builtin_popcountll(x)
#define sov(v) accumulate(all(v),0)
#define fs(it,a) for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pqmax priority_queue <int,vector <int>> 
#define pqmin priority_queue <int,vector <int>,greater<int>> 
#define dq deque <int>
#define umi unordered_map<int,int>
#define ums unordered_map<string,int>
#define ps(x,y) fixed << setprecision(y) << x
#define all(x) x.begin(),x.end()
#define f(x,y,z) for(x=y;x<z;x++)
#define si size()
#define ps(x,y) fixed << setprecision(y) << x
#define countdigit(x) floor( log10(x) +1)
#define M 1000000007  
#define PI 3.1415926535
//Use (k%M+m)%m always where k is any no
#define ee "\n"
#define re return 



//Author Rahul Sannigrahi


vector<int> take(int n)
{
    int i,j;
    vi v;
    f(i,0,n)
    {
        cin>>j;
        v.pb(j);
    }
    return v;
}

void show(vector<int>v)
{
    int i;
    for(i=0;i<v.si;i++)
    {
     cout<<v[i]<<" ";   
    }
    cout<<ee;
}

int decode()
{
    int i,j,k,l,n,m;
    cin>>n;
    vi v=take(n);
    vi pes(n);
    pes[v.si-1]=v[v.si-1];
    
    for(i=v.si-2;i>=0;i--)
    {
        pes[i]=pes[i+1]+v[i];
    }
    //show(pes);
    l=0;
    f(i,0,v.si-1)
    l=(l%M+((v[i]%M)*(pes[i+1]%M)+M))%M;
    cout<<l<<ee;
    re 0;
}
 
int32_t main()
{
    IOS
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    // #endif 
    int t=1;
    //cin>>t;
    while(t--)
    decode();
    return 0;
}
 











