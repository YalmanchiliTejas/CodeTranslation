#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A[N];
  int maxa = 0;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(maxa <= A[i]) {
      ans++;
      maxa = A[i];
    }
  }
  cout << ans << endl;
}