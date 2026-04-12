#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const string YES = "Yes";
const string NO = "No";

void solve(std::string S) {
    if( S.size() == count(S.begin(), S.end(), S[0])){
        cout << NO<< endl;
    }else{
        cout << YES << endl;
    }

}

int main() {
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}
