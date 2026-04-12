#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vector<int>>;  // int <=> ll
using P = pair<int, int>;
const int INFTY = 1e9+7;

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) cin >> A[i];

  vi vec;  // descending order
  rep(i,N) {
    vec.push_back(-1);
    bool greatest = true;
    for (int j=vec.size()-2; j>=0; j--) {
      if (vec[j] >= A[i]) {
        vec[j+1] = A[i];
        greatest = false;
        break;
      }
    }
    if (greatest) vec[0] = A[i];
    if (vec.back() == -1) vec.pop_back();
  }

  cout << vec.size() << endl;
  return 0;
}
