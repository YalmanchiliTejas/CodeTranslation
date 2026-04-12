#include <bits/stdc++.h>
using namespace std;
int A,B,C,D,N,M;
int h[10000];
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> h[i];
  }
int max = 0;
int num = 0;
  for(int i = 0; i < N; i++) {
    if(max <= h[i]) {
      num++;
      max = h[i];
    }
  }
  cout << num;


  return 0;
}
