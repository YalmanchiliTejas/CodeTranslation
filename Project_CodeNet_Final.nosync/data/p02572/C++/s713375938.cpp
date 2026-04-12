#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n;
  cin>>n;

  long long int A[n];
  long long int MOD=1000000007;
  long long int ans=0;
  long long int sum=0;
  for(int i=0; i<n; i++) cin>>A[i];

  for(int i=0; i<n; i++){
    sum +=A[i];
    sum %= MOD;
  }

  for(int i=0; i<n-1; i++){
    sum = sum- A[i];
    if(sum<0) sum+=MOD;
    ans+=sum*A[i];
    ans%=MOD;
  }

  cout<<ans<<endl;
}
