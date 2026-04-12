#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

using namespace std;
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define N 3010
ll f[N][N],n,a[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int l=0;l<n;l++){
     for(int i=0;i+l<n;i++){
      int j=i+l;
      if(n%2==l%2){
       if(i==j)f[i][j]=-a[i];
       else f[i][j]=min(f[i+1][j]-a[i],f[i][j-1]-a[j]);   
      }
      else{
          if(i==j)f[i][j]=a[i];
            else f[i][j]=max(f[i+1][j]+a[i],f[i][j-1]+a[j]);   
      }
     }
    }
    cout<<f[0][n-1]<<endl;
 return 0;   
}