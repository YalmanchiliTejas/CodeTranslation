#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U> void cmin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U> void cmax(T &a, U b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());

  auto f = [&](auto V) {
    int n = V.size();
    long res = 0;
    for (int i = 0; i + 1 < n; i++) {
      res += abs(V.at(i) - V.at(i + 1));
    }
    return res;
  };

  if (N % 2) {
    
    vector<int> C1;
    for (int i = 0; i < N / 2; i++) {
      C1.push_back(A.at(i));
      C1.push_back(A.at(N - 1 - i));
    }
    auto C2 = C1;
    C1.push_back(A.at(N / 2));
    C2.insert(C2.begin(), A.at(N / 2));
    
    vector<int> C3;
    for (int i = 0; i < N / 2; i++) {
      C3.push_back(A.at(N - 1 - i));
      C3.push_back(A.at(i));
    }
    auto C4 = C3;
    C3.push_back(A.at(N / 2));
    C4.insert(C4.begin(), A.at(N / 2));

    cout << max({f(C1), f(C2), f(C3), f(C4)}) << "\n";
    
  } else {

    int x = A.at(N / 2 - 1);
    int y = A.at(N / 2);

    vector<int> C1;
    for (int i = 0; i < N / 2 - 1; i++) {
      C1.push_back(A.at(i));
      C1.push_back(A.at(N - 1 - i));
    }
    auto C2 = C1;
    C1.push_back(x);
    C1.insert(C1.begin(), y);
    C2.push_back(y);
    C2.insert(C2.begin(), x);
    
    vector<int> C3;
    for (int i = 0; i < N / 2 - 1; i++) {
      C3.push_back(A.at(N - 1 - i));
      C3.push_back(A.at(i));
    }
    auto C4 = C3;
    C3.push_back(x);
    C3.insert(C3.begin(), y);
    C4.push_back(y);
    C4.insert(C4.begin(), x);

    cout << max({f(C1), f(C2), f(C3), f(C4)}) << "\n";

  }
}
