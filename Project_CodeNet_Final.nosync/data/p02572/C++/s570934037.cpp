#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int main(){
  int n;
  long long int ans=0,s1=0;
  cin>>n;
  const int N=n;
  long long int a[N];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=n-1;i>0;i--){
    s1=(s1+a[i])%MOD;
    ans=(ans+s1*a[i-1])%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
