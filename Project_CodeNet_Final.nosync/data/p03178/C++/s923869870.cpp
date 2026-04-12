#include<bits/stdc++.h> 
using namespace std;
#define se second
#define fr first
#define int long long int
#define pb push_back
#define inf 1e18
#define all(v) v.begin(),v.end()
#define CHAL_BAAP_KO_MT_SIKHA ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
/*
    Damn Fast:TheFuckinMastermind
    while(How to solve the Question?){
                Read the Question Again!!
           }
        do
            Practise
    #Motivation::::0/0  
*/
const int N=2e4;
int dp[N+1][101][2];
int n,d;
vector<int> v;
int solve(int idx,int sum,int tight){
    if(idx==n)
    {
        return sum==0;
    }
    if(dp[idx][sum][tight]!=-1)
        return dp[idx][sum][tight];
    int lmt=(tight)?9:v[idx];
    int ans=0;
    for(int i=0;i<=lmt;i++){
        int new_sum=(sum+i)%d;
        ans+=solve(idx+1,new_sum,tight|(i<v[idx]));
        ans%=mod;
    }
    return dp[idx][sum][tight]=ans;
}
signed main()
{
    CHAL_BAAP_KO_MT_SIKHA
    string s;
    cin>>s>>d;
    n=s.length();
    for(int i=0;i<n;i++){
        v.pb(s[i]-'0');
    }
    memset(dp,-1,sizeof(dp));
    int x=(solve(0,0,0)-1+mod)%mod;
    cout<<x<<endl;
}