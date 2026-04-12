#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> inp;
vector<vector<vector<ll>>> dp;

ll dopont_dequ (int i=0,int j=n-1,int c = 1)
{
    //cout<<i<<" "<<j<<" "<<c<<" "<<sum<<'\n';
    if(i>j) return 0;
    if(dp[i][j][c] != -1) return dp[i][j][c];

    ll ans = 0;
    if(c)
    {
        ans = dopont_dequ(i+1,j,0)+inp[i];
        ans = max(ans,dopont_dequ(i,j-1,0)+inp[j]);
    }
    else
    {
        ans = dopont_dequ(i+1,j,1)-inp[i];
        ans = min(ans,dopont_dequ(i,j-1,1)-inp[j]);
    }
    
    
    return dp[i][j][c]=ans;
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //int k;
    cin>>n;//>>k;
    inp.resize(n);
    dp.assign(n+1,vector<vector<ll>> (n+1,vector<ll> (2,-1)));

    for(int i=0;i<n;i++)
    {
        cin>>inp[i];
    }

    cout<<dopont_dequ()<<'\n';
    /*for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)*/

}
