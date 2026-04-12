#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long n,b,ans=10000,sum=0;
  cin>>n;

  for(int day=1;day<=n;day++){
    cin>>b;
    sum+=b;
    ans=min(ans, sum/day);
  }

  cout<<ans<<endl;
  return 0;
}

