#include <iostream>
using namespace std;
typedef long long ll;
ll a[100];
ll n;
int main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  ll cnt = 0;
  for(int i=0;i<100000;++i){
    for(int j=0;j<n;++j){
      ll x = a[j]/n;
      a[j]%=n;
      for(int k=0;k<n;++k)
	if(k!=j)
	  a[k]+=x;
      cnt+=x;
    }
  }
  cout << cnt << endl;
  return 0;
}
