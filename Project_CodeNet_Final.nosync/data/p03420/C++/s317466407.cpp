#include <bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second
int h,w;
int dp[100009];
signed main(){
  int n,k;
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  int sum=0;
  for(int i=k+1;i<=n;i++){
    int p=n/i;
    int x=n%i;
    sum+=(i-k)*p;
    if(x>=k)sum+=(x-k+1);
  }
  cout<<sum<<endl;
}