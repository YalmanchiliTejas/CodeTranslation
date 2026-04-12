#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

const int N_MAX = pow(10,5)+10;

int main() {
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];
  int now = INF;
  vector<int> ml;
  for(int i=N-1; i>=0; i--) {
    if (i==N-1) { ml.push_back(A[i]); continue; }
    if (*(ml.end()-1)<=A[i]) { ml.push_back(A[i]); continue; }
    *(upper_bound(ml.begin(), ml.end(), A[i])) = A[i];
  }
  // rep(i,ml.size()) cout << ml[i] << " "; cout << endl;
  int result = ml.size();
  cout << result << endl;
  return 0;
}