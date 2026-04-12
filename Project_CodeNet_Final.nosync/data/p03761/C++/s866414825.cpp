#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000000;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}



int main() {
  int n;
  cin >> n;
  vector<vector<int>> tmp(n, vector<int>(26));
  rep(i, n){
    string s;
    cin >> s;
    for(char c : s){
      tmp[i][c - 'a']++;
    }
  }

  vector<int> ans(26);
  rep(i, 26){
    int tmp2 = 30000;
    rep(j, n){
      tmp2 = min(tmp2, tmp[j][i]);
    }
    ans[i] = tmp2;
  }

  rep(i, 26){
    int count = ans[i];
    rep(j, count){
      cout << (char)(i + 'a');
    }
  }
  cout << endl;
  return 0;
}
