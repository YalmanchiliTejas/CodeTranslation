#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[3005];
int f[3005][3005];
int n;

int F(int u,int v)
{
  if(u==v){
            if((n)%2) f[u][v]=a[u];
            else f[u][v]=-a[u];
          }
  if(f[u][v]) return f[u][v];
  if((u+v)%2!=n%2)
  f[u][v]=max(F(u,v-1)+a[v],F(u+1,v)+a[u]);
  else
  f[u][v]=min(F(u,v-1)-a[v],F(u+1,v)-a[u]);
  return f[u][v];
}

main()
{


  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<F(0,n-1);
 // cout<<f[0][0]<<endl;
}
