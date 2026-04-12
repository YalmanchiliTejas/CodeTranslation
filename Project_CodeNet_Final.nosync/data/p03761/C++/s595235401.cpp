#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;

  std::vector<int> alphabet(26,0);
  std::vector<int> tmp(26,0);
  rep(i,n){
    string s; cin >> s;
    int sizes = s.size();
    rep(j,sizes) {
      int k = s.at(j);
      k = k - 97;
      tmp.at(k)++;
    }
    if(i == 0) {
      rep(j,26) {
        alphabet.at(j) = tmp.at(j);
      }
    }
    else{
      rep(j,26) {
        alphabet.at(j) = min(alphabet.at(j), tmp.at(j));
      }
    }

    rep(j,26){
      tmp.at(j) = 0;
    }
    
  }

  rep(i,26) {
    if(alphabet.at(i) != 0) {
      int tmp_alp_num = i + 97;
      char tmp_alp = tmp_alp_num;
      int count = alphabet.at(i);
      rep(j,count) {
        cout << tmp_alp;
      }
      
    }
  }

  cout << endl;
}

