#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  long long ans=0;
  if(k==0){
    ans=n*n;
  }else{
    for(int i=k+1;i<=n;i++){
      if(n%i){
        ans+=(long long)((n/i)*(i-k)+((n%i+1>=k)?(n%i+1-k):0));
      }else{
        ans+=(long long)((n/i)*(i-k));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
