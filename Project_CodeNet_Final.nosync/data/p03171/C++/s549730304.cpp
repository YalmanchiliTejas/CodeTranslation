#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<long long> > dp(3001, vector<long long> (3001, -1));
vector<long long> A;
long long solve(int i ,int j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int p = (j-i+1)%2;
    if(p==m)
    {
       dp[i][j] = max(A[i]+ solve(i+1,j), solve(i,j-1)+A[j]);
    }
    else
       dp[i][j] = min( solve(i+1,j) - A[i], solve(i,j-1)-A[j]);

    return dp[i][j];
}
int main()
{
   cin>>n;
   A.resize(n);
   for(int i=0; i<n; i++)
      cin>>A[i];

   m = n%2;
   long long ans = solve(0,n-1);
   cout<<ans;
   return 0;

}
