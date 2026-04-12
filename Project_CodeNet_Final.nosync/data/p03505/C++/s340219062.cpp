#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long

signed main(){
  int K,A,B;cin>>K>>A>>B;
  if(K<=A){cout<<1<<endl;return 0;}
  if(A<=B){cout<<-1<<endl;return 0;}
  cout<<((K-A-1)/(A-B)+1)*2+1<<endl;
}
