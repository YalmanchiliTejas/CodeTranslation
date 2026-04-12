#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n) cin >> h[i];
  int ma = h[0];
  int ans=1;
  repi(i,1,n){
    if(ma<=h[i]){
      ans++;
      ma = max(ma,h[i]);
    }
  }
  cout << ans << endl;
  
  return 0;
}