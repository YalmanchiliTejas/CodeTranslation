#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
//#define double ld
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ifstream in("input.txt");ofstream out("output.txt");
const int inf=1e18;
const int mod=1e9+7;
int n,k;
vector<int> vec;
vector<vector<int> > dp;

void init()
{
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    dp.resize(n,vector<int>(n,inf));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
        if((i+i)%2==(n-1)%2)
            dp[i][i]+=vec[i];
        else
            dp[i][i]-=vec[i];
    }
}

int go(int l,int r)
{
    if(l<0||r<0||l>=n||r>=n)
        return inf;
    if(dp[l][r]!=inf)
        return dp[l][r];
    int ans;
    if((l+r)%2==(n-1)%2)
    {
        ans=-inf;
        if(go(l+1,r)!=inf)
            ans=max(ans,go(l+1,r)+vec[l]);
        if(go(l,r-1)!=inf)
            ans=max(ans,go(l,r-1)+vec[r]);
    }
    else
    {
        ans=min(-vec[l]+go(l+1,r),-vec[r]+go(l,r-1));
    }
    return dp[l][r]=ans;
}

signed main()
{
    init();
    cout<<go(0,n-1)<<"\n";
    return 0;
}


