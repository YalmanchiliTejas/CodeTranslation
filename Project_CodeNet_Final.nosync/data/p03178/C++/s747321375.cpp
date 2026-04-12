#include<bits/stdc++.h>
using namespace std;
const int size=1e4+5;
const int mod=1e9+7;
using ll = long long int;
ll dp[size][105][2];
void add(ll &a,ll b)
{
    a = (a+b);
    a %= mod;
}
ll solve(int idx,int rem,bool flag,int arr[],int n,int d)
{
//    cout<<idx<<" "<<rem<<" "<<flag<<endl;
    if(idx==n)
    {
        return (rem==0);
    }
    int limit = ((flag)?9:arr[idx]);
//    if(dp[idx][(d-rem)%d]!=-1)
//        return dp[idx][(d-rem)%d];
    ll &res = dp[idx][rem][flag];
    if(res!=-1)
        return res;
    res = 0;
    for(int i=0;i<=limit;i++)
    {
        add(res,solve(idx+1,(rem+i)%d,(flag|(i!=arr[idx])),arr,n,d));
    }
    return res;
}
int main()
{
    memset(dp,-1,sizeof dp);
    string s;
    cin>>s;
    int n = s.size();
    int d;
    cin>>d;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i] = (s[i]-'0');
    cout<<(solve(0,0,0,arr,n,d)-1+mod)%mod<<"\n";
    return 0;
}
