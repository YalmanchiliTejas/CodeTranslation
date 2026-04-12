#include<bits/stdc++.h>

using namespace std;

bool v[5000][5000];


int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  map< int, int > mp;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(begin(A), end(A));
  for(int i = 0; i < N; i++) {
    mp[A[i]] = i;
  }

  int ret = 1;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(v[i][j]) continue;
      v[i][j] = true;
      int sa = A[j] - A[i];
      ret = max(ret, 2);
      int pre = j;
      for(int k = A[j] + sa, l = 3;; k += sa, l++) {
        if(!mp.count(k)) {
          ret = max(ret, l - 1);
          break;
        }
        v[pre][mp[k]] = true;
        pre = mp[k];
      }
    }
  }

  cout << ret << endl;

}
