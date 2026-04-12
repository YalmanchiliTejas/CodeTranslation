#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string S;
  cin >> S;
  if (S.at(0) != S.at(1) || S.at(1) != S.at(2) || S.at(2) != S.at(0)) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}