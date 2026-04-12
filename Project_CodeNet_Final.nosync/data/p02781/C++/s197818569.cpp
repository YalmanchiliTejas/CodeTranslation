#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
string a,b;
ll k;
int n;
ll dp[105][2][2][5];
ll fun(int pos,int boro,int choto,int nw)
{
    if(nw>k)
    {
        return 0;
    }
    if(pos==n)
    {
        if(k==nw)
        {
            return 1LL;
        }
        return 0;
    }
    if(dp[pos][boro][choto][nw]!=-1)
        return dp[pos][boro][choto][nw];
    int lw=0;
    int hi=9;
    if(boro==0) lw=a[pos]-'0';
    if(choto==0) hi=b[pos]-'0';
    ll ret=0;
    for(int i=lw;i<=hi;i++)
    {
        if(i!=0) ret += fun(pos+1,boro|(i>lw),choto|(i<hi),nw+1);
        else ret += fun(pos+1,boro|(i>lw),choto|(i<hi),nw);
    }
    return dp[pos][boro][choto][nw]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>b>>k)
    {
        for(int i=0;i<b.size();i++)
        {
            a.push_back('0');
        }
        n=b.size();
        memset(dp,-1,sizeof dp);
        cout<<fun(0,0,0,0)<<endl;
    }
    return 0;
}
