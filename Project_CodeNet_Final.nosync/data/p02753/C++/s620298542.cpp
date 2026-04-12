#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string t;
  cin>>t;
  
  string ans="Yes";
  if(t=="AAA" or t=="BBB"){
    ans="No";
  }
  cout<<ans;
  
  return 0;
}