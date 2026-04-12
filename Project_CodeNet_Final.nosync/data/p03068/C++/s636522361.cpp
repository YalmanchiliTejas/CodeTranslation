#include <bits/stdc++.h>
using namespace std;
int A,B,C,D,N,M;
string in;
int K;
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  cin >> in;
  cin >> K;
  char t = in[K-1];
  for(int i = 0; i < N; i++) {
    if(in[i] == t) cout << t;
    else cout << '*';
  }


  return 0;
}
