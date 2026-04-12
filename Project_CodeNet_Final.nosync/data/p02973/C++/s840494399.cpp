#include<iostream>
#include<set>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  multiset<int> S;
  for (int i = 0; i < N; i++) {
    auto it = S.lower_bound(A[i]);
    if (it != S.begin()) {
      S.erase(prev(it));
    }
    S.insert(A[i]);
  }
  cout << S.size() << endl;
}