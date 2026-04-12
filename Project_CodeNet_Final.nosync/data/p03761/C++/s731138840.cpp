#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll n;
  bool blank = 0;
  cin >> n;
  string S;
  vector<ll> A(26, 0), B(26, 0);
  for(ll i = 0; i < n; i++) {
    cin >> S;
    vector<ll> B(26, 0);
    if(i == 0) {
      for(ll j = 0; j < S.size(); j++) {
        A.at(S.at(j) - 97)++;
      }
    }
    else {
      for(ll j = 0; j < S.size(); j++) {
        B.at(S.at(j) - 97)++;
      }
      for(ll j = 0; j < 26; j++) {
        A.at(j) = min(A.at(j), B.at(j));
      }
    }
  }
  for(ll i = 0; i < 26; i++) {
    if(A.at(i) != 0) break;
    if(i == 25) blank = 1;
  }
  if(blank == 1) cout << endl;
  else {
    for(ll i = 0; i < 26; i++) {
      for(ll j = 0; j < A.at(i); j++) cout << char(i + 97);
    }
  }
}