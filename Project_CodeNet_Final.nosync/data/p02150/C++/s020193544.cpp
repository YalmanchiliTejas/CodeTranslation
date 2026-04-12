#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll a,b,x;
  cin>>a>>b>>x;

  if(x<a){
    cout<<x%MOD<<endl;
    return 0;
  }
  
  ll ans=(x-a)/(a-b)+1;
  ans%=MOD;
  b%=MOD;
  x%=MOD;
  ans=ans*b%MOD+x;
  ans=(ans+MOD)%MOD;
  cout<<ans<<endl;

  return 0;
}

