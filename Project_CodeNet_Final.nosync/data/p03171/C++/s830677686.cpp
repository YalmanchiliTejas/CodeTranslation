#include<iostream>
#include<cstring>
using namespace std;

/*long mem[3001][3001];

long rec(int a[], int n, int i, int j, int ch)
{
  if(i==j)
    return ch?-a[i]:a[i];
  if(mem[i][j]!=1e9+5)
    return mem[i][j];
  long ans=0;
  long ans1=rec(a,n,i+1,j,!ch);
  long ans2=rec(a,n,i,j-1,!ch);
  if(ch==0) 
    ans=max(ans1+a[i],ans2+a[j]);
  else
    ans=min(ans1-a[i],ans2-a[j]);
  mem[i][j]=ans;
  return ans;
}*/

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  /*for(int i=0;i<=3000;i++)
  {
  	for(int j=0;j<=3000;j++)
  		mem[i][j]=1e9+5;
  }
  cout<<rec(a,n,0,n-1,0)<<endl;*/
  
  
  long dp[n+1][n+1];
  int sign=n%2?1:-1;
  for(int i=0;i<n;i++)
  {
    dp[i][0]=0;
    dp[0][i]=0;
    dp[i][i]=a[i]*sign;
  }
  int ch=0;
  for(int i=2;i<=n;i++)
  {
  	ch=0;
    for(int j=0;j+i<=n;j++)
    {
      int right=j+i-1;
      ch=(n-(right-j+1))%2;
      if(ch==0)
      {
        dp[j][i+j-1]=max(dp[j+1][i+j-1]+a[j],dp[j][i+j-2]+a[i+j-1]);
        ch=1;
      }
      else
      {
        dp[j][i+j-1]=min(dp[j+1][i+j-1]-a[j],dp[j][i+j-2]-a[i+j-1]);
        ch=0;
      }
    }
  }
  cout<<dp[0][n-1];
  
}