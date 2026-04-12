#include <bits/stdc++.h>
using namespace std;

vector<int> A[8];
int ans = 0;
int N;

void search(int a, int bit){
  if(a<0||a>=N) return;
  bit |= (1<<a);
  if (bit == (1<<N)-1) ans++;
  else {
    for (auto i: A[a]) {
      if(!(bit&(1<<i))) search(i, bit);
    }
    return;
  }
}
  
int main() {
  int M, a, b, bit=0; cin >> N >> M;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  search(0, bit);
  cout << ans << "\n";
}