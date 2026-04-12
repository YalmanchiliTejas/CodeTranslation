#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define endl '\n'
#define line cout<<"----------------------"<<endl
#define mp make_pair
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll  mx=2000009;
ll  dp[3009][3009];
ll  ara[3009];
ll  call(ll  i,ll  j)
{
    if(i>j) return 0;
    ll  &ret=dp[i][j];
    if(ret!=-1) return ret;
    ll  a=0,b=0;
    a=ara[i]-call(i+1,j);
    b=ara[j]-call(i,j-1);
    return ret=max(a,b);
}
int main()
{
    ll  n;
    cin>>n;
    for(ll  i=0;i<n;i++) cin>>ara[i];
    memset(dp,-1,sizeof dp);
    cout<<call(0,n-1)<<endl;
}



