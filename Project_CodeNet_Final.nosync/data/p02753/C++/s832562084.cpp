#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  if(count(S.begin(), S.end(), 'A') == 0 || count(S.begin(), S.end(), 'B') == 0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}