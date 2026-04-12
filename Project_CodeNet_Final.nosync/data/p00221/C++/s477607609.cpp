#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int M, N;
  while(cin >> M >> N, M) {
    bool v[1000] = {};
    int cur = 0, rest = M;

    for(int i = 1; i <= N; i++) {
      string x;
      cin >> x;

      if(rest > 1) {
        string ans;
        if(i % 15 == 0) ans = "FizzBuzz";
        else if(i % 3 == 0) ans = "Fizz";
        else if(i % 5 == 0) ans = "Buzz";
        else ans = to_string(i);

        if(x != ans) {
          v[cur] = true;
          --rest;
          while(v[cur]) cur = (cur + 1) % M;
        } else {
          cur = (cur + 1) % M;
          while(v[cur]) cur = (cur + 1) % M;
        }
      }
    }
    bool f = false;
    for(int i = 0; i < M; i++) {
      if(!v[i]) {
        if(f++) cout << " ";
        cout << i + 1;
      }
    }
    cout << endl;
  }
}

