#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string str;
  cin >> str;

  if (str[0] == 'A') {
    rep(i,3) {
      if (str[i] == 'B') {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }else {
    rep(i,3) {
      if (str[i] == 'A') {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}

