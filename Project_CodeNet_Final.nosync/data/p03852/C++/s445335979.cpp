#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main() {
  char c;
  cin >> c;
  if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o'){cout << "vowel" << endl;}
  else{cout << "consonant" << endl;}
}