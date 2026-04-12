#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0,tmp=0;
  cin >> n;
  long long a[n];
  vector<long long> small,big;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      small.push_back(a[i]);
    }
    for(int i=n-1;i>=n/2;i--){
      big.push_back(a[i]);
    }
    for(int i=0;i<n/2-1;i++){
      ans+=big[i]-small[i];
    }
    for(int i=0;i<n/2-1;i++){
      ans+=big[i]-small[i+1];
    }
    ans+=max(big[n/2-1]-small[0], big[n/2-1]-small[n/2-1]);

    for(int i=0;i<n/2-1;i++){
      tmp+=big[i]-small[i];
    }
    for(int i=0;i<n/2-1;i++){
      tmp+=big[i+1]-small[i];
    }
    tmp+=max(big[0]-small[n/2-1], big[n/2-1]-small[n/2-1]);
  }

  else{
    for(int i=0;i<=(n-1)/2;i++){
      small.push_back(a[i]);
    }
    for(int i=n-1;i>(n-1)/2;i--){
      big.push_back(a[i]);
    }
    for(int i=0;i<(n-1)/2;i++){
      ans+=big[i]-small[i];
    }
    for(int i=0;i<(n-1)/2-1;i++){
      ans+=big[i+1]-small[i];
    }
    ans+=max(big[0]-small[(n-1)/2], small[(n-1)/2]-small[(n-1)/2-1]);

    for(int i=0;i<(n-1)/2;i++){
      tmp+=big[i]-small[i];
    }
    for(int i=0;i<(n-1)/2-1;i++){
      tmp+=big[i]-small[i+1];
    }
    tmp+=max(small[(n-1)/2]-small[0], big[(n-1)/2-1]-small[(n-1)/2]);

  }

  cout << max(ans,tmp) << endl;
  return 0;
}
