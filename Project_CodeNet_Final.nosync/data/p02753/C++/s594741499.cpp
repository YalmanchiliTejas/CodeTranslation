#include<bits/stdc++.h>
#define rep(i, n) for(i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
 
int main(){
  ll N, i, flag = 1;
  string S, ans = "No";
  cin >> S;
  rep(i, S.size() - 1){
    if(S[i] != S[i + 1]){
      flag = 0;
      break;
    }
  }
  if(!flag){
    ans = "Yes";
  }
 
  cout << ans << endl;
  return 0;
}
