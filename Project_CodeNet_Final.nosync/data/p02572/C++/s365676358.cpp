/*
Author: Hrujul Thumar
*/
#include <bits/stdc++.h>
#define int         long long
#define pb          push_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define whilet()    int t; scanf("%d",&t); while(t--)
#define vp          vector<pair<int,int>,int>
#define pb          push_back
#define mii         map<int,int>
#define pii         pair<int,int>
#define msi         map<string,int>
#define psi         pair<string,int>
#define mpi         map<pair<int,int>,int>
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define ef          else if
#define MOD         1000000007
#define endl        '\n'
#define fastio       ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define pi          3.141592653589793238
const long long MAX_SIZE = 1000000000;
using namespace std;

signed main()
{
    fastio
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    int pre[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)pre[i]=pre[i-1]%MOD+a[i]%MOD;
        else pre[i]=a[i];
    }
    for(int i=n-1;i>=1;i--)
    {
        ans=ans%MOD+((a[i]%MOD)*(pre[i-1])%MOD)%MOD;
        //cout<<pre[i-1]<<" "<<ans<<endl;
    }
    cout<<ans%MOD<<endl;
}
