#include <bits/stdc++.h>
using namespace std;

int main()
{
int N,ans,s,f,middle,j;scanf("%d",&N);
vector<int> A(N);for(int i=0;i<N;i++)scanf("%d",&A[i]);
vector<int> dp(N,-1);
for(int i=0;i<N;i++)
{
  f=-1,s=N;
  while(s-f>1)
  {
    middle=(f+s)/2;
    if(dp[middle]<A[i])s=middle;
    else f=middle;
  }
  dp[s]=A[i];
}
for(j=0;j<N;j++){if(dp[j]==-1)break;}
if(j==N-1&&dp[j]!=-1)j--;
printf("%d\n",j);
}
