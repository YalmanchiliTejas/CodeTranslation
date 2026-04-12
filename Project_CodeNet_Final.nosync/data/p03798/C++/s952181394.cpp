#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

char inv(char x){
  if(x == 'S') return 'W';
  else return 'S';
}

int main(){
  int n;
  string data;
  cin >> n >> data;
  vector<char> ans(n);
  bool flag1 = false;
  bool flag2 = false;
  rep(a,2){
    rep(b,2){
      if(a) ans.at(0) = 'S';
      else ans.at(0) = 'W';
      if(b) ans.at(1) = 'S';
      else ans.at(1) = 'W';
      for(int i=1;i<n-1;i++){
        if(data.at(i) == 'o'){
          if(ans.at(i) == 'S') ans.at((i+1)%n) = ans.at(i-1);
          else ans.at((i+1)%n) = inv(ans.at(i-1));
        }else{
          if(ans.at(i) == 'S') ans.at((i+1)%n) = inv(ans.at(i-1));
          else ans.at((i+1)%n) = ans.at(i-1);
        }
      }
      if(data.at(0) == 'o'){
        if(ans.at(0) == 'S'){
          if(ans.at(n-1) == ans.at(1)) flag1 = true;
        }else{
          if(ans.at(n-1) != ans.at(1)) flag1 = true;
        }
      }else{
        if(ans.at(0) == 'S'){
          if(ans.at(n-1) != ans.at(1)) flag1 = true;
        }else{
          if(ans.at(n-1) == ans.at(1)) flag1 = true;
        }
      }
      if(data.at(n-1) == 'o'){
        if(ans.at(n-1) == 'S'){
          if(ans.at(n-2) == ans.at(0)) flag2 = true;
        }else{
          if(ans.at(n-2) != ans.at(0)) flag2 = true;
        }
      }else{
        if(ans.at(n-1) == 'S'){
          if(ans.at(n-2) != ans.at(0)) flag2 = true;
        }else{
          if(ans.at(n-2) == ans.at(0)) flag2 = true;
        }
      }
      if(flag1 && flag2) break;
      flag1 = false;
      flag2 = false;
    }
    if(flag1 && flag2) break;
  }
  if(flag1 && flag2){
    rep(i,n) cout << ans.at(i);
    cout << endl;
  }else{
    cout << -1 << endl;
  }
}
