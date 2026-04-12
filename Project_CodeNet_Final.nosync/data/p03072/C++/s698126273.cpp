#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

int main(){
  int n;cin >> n;
  int M=0;
  int ans=0;
  rep(i,n){
    int t;cin >> t;
    if(t>=M){
      ans++;
      M=t;
    }
  }
  cout << ans << endl;
}