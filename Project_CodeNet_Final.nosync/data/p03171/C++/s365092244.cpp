#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bg=pow(10,9)+7;
#define ff(i,n) for(i=0;i<n;i++)
#define gg1(n1) cin>>n1;
#define gg(n1,n2) cin>>n1>>n2;
#define gg3(n1,n2,n3) cin>>n1>>n2>>n3;
#define hh(n) cout<<n<<endl;
#define t top
#define p push
#define pb push_back
#define mp make_pair
ll arr[4000],x[4000][4000],y[4000][4000];
int main()
{
  ll i,j,n,k;
  cin>>n;
  for(i=0;i<n;i++)  
  {
         cin>>arr[i];
         x[0][i]=arr[i];
         y[0][i]=-arr[i];
  }
  for(i=1;i<n;i++)
  {
       for(j=0;j<n-i;j++)
       {
          x[i][j]=max(arr[j]+y[i-1][j+1],arr[j+i]+y[i-1][j]);  
          y[i][j]=min(-arr[j]+x[i-1][j+1],-arr[j+i]+x[i-1][j]);  
       }
  }

  cout<<x[n-1][0];
  return 0;
}