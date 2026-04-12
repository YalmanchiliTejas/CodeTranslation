#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long

signed main(){
  int N;cin>>N;
  std::vector<char> v(N);
  for(int i=0;i<N;i++){
    cin>>v[i];
    if(v[i]=='T')v[i]=1;
    else v[i]=0;
  }
  int now=v[0];
  for(int i=1;i<N;i++){
    if(now&&!v[i])now=0;
    else now=1;
  }
  if(now)cout<<"T"<<endl;
  else cout<<"F"<<endl;
}

