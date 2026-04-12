#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpii = vector<pll>;

int main(){
  string S;
  cin >> S;

  for(int i = 1; i <= 2; i++){
    if(S[i] != S[i-1]){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  
  return 0;
}
