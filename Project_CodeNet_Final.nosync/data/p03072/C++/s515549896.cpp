#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  int ans = 1;
  for(int i=1;i<n;i++){
    for(int j=0;j<=i;j++){
      if(h[j] > h[i]) break;
      if(j == i) ans++;
    }
  }
  cout << ans << endl;
}