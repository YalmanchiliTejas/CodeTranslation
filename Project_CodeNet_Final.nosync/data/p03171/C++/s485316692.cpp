//Om Sree Sai Ram
#include "bits/stdc++.h"
using namespace std;

template <typename T> void max_self(T& a,T b)
{
  a = max(a,b);
}

const int nax = 305;
double p[nax][nax][nax], ex[nax][nax][nax];


int main() 
{


int n;
cin>>n;
vector<long long> ar(n);
for(int i=0;i<n;i++)
{
  cin>>ar[i];
}

vector<vector<long long>> dp(n,vector<long long>(n));
//dp[L][R] represents score (X-Y) we can obtain from taking array from L to R
for(int L=n-1;L>=0;L--)
{
  for(int R=L;R<n;R++)
  {
    if(L==R)
    {
      dp[L][R] = ar[L];
    }
    else
    {
      //maximizing this gets the answer that's magic..
   dp[L][R] = max(ar[L]-dp[L+1][R],ar[R]-dp[L][R-1]);
    }

  }
}
  cout<<dp[0][n-1]<<endl; 
}
