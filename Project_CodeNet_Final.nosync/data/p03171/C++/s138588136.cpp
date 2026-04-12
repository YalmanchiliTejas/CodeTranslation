#include <bits/stdc++.h>
#define chmin(x, v) x = min(x, v)
#define chmax(x, v) x = max(x, v)
#define int long long
using namespace std;

int dp[2][3000][3000];
int v[3000];

int r(int s, int e, int t)
{
    if (s==e)
    {dp[t][s][e] = v[s];if(t%2)return -v[s];else return v[s];}
    if (dp[t][s][e])return dp[t][s][e];
    
    if (t%2==0)
        dp[t][s][e] = max(r(s+1, e, 1-t)+v[s], r(s, e-1, 1-t)+v[e]);
    else
        dp[t][s][e] = min(r(s+1, e, 1-t)-v[s], r(s, e-1, 1-t)-v[e]);
   // cout <<t << " " << s << " " << e << endl;
    return dp[t][s][e];
}

signed main()
{
   int n;cin>>n;for(int i=0;i<n;++i)cin>>v[i];
   cout << r(0, n-1, 0) << endl;
  /* cout << endl;
   for (int k=0;k<2;++k){
   for (int i=0;i<n;++i)
   {
       for (int j=0;j<n;++j)cout<<dp[k][i][j]<<" ";
       cout << endl;
   }cout<<"-------\n\n";}*/
   return 0;
}