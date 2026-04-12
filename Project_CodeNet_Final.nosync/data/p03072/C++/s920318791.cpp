#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  int N;cin>>N;
  int ma=0;
  int ans=0;
  for(int i=0;i<N;i++){
    int a;cin>>a;
    if(a>=ma)ans++;
    ma=max(a,ma);
  }
  cout<<ans<<endl;
}
