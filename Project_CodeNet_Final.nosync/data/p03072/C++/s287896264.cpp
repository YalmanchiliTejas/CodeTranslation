#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  int ans=0;
  int n;cin>>n;
  int mx=0;
  for(int i=0;i<n;i++){
    int t;cin>>t;
    if(t>=mx){
      ans++;
      mx = max(t,mx);
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
