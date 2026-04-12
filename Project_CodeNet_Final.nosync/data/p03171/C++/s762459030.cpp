#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3001][3001];
ll maxScore(vector<int> money)
{
   int n = money.size();
   int totalTurns = n;
   bool turn = (totalTurns%2==0)?0:1;
   for(int i = 0; i < n ; i++)
   {
       dp[i][i] = turn?money[i]:0;
   }
   turn = !turn;
   int sz = 1;
   while(sz < n)
   {
       for(int i = 0; i + sz < n ;i++)
       {
           ll scoreOne = dp[i+1][i+sz];
           ll scoreTwo = dp[i][i+sz-1];
           if(turn)
           {
              dp[i][i+sz] = max(money[i] + scoreOne, money[i+sz] + scoreTwo);
           }
           else dp[i][i+sz] = min(scoreOne, scoreTwo);
       }
       turn = !turn;
       sz++;
   }
   return dp[0][n-1];
}

int main()
{
   ll n,x;
   cin>>n;
   vector<int> v(n); ll sum =0;
   for(int i=0;i<n;i++)
   {
       cin>>v[i]; sum += v[i];
       //v.push_back(x);
   }
   cout<<2*maxScore(v) - sum;
    return 0;
}

