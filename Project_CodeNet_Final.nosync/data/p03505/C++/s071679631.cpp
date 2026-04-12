#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;
const int INF=1e9;

signed main(){
  int k,a,b;
  cin>>k>>a>>b;
  int p=a-b;
  if(k<=a){
    cout<<1<<endl;
    return 0;
  }
  if(p<=0){
    cout<<-1<<endl;
    return 0;
  }
  int ans=(k-a)/p;
  if((k-a)%p!=0)ans++;
  cout<<ans*2+1<<endl;
}
