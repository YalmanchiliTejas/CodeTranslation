/*
  Reference:-
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
ll mod=1000000007;
const int N=2e5 + 5;
string s;
int n,d;
ll dp[10005][105][2];
ll sol(int pos,int rem,int fl){
    ll one=1,zero=0;
    if(pos==n){
        if(rem==0)return one;
        else return zero;
    }
    if(dp[pos][rem][fl]!=-1)return dp[pos][rem][fl];
    int lim=9;
    if(fl==1)lim=s[pos]-'0';
    ll ans=0;
    forn(i,lim+1){
        int fl1=fl;
        if(fl==1&&i<lim)fl1=0;
        ans=(ans+sol(pos+1,(rem+i)%d,fl1))%mod;
    }
    dp[pos][rem][fl]=ans;
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>s>>d;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    ll ans=sol(0,0,1);
    ans=(ans-1+mod)%mod;
    cout<<ans;

    return 0;
}
