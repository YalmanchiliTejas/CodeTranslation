// https://atcoder.jp/contests/abc124/tasks/abc124_b
#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int H[N] = {0};
  for (int i = 0; i < N; i++)  cin >> H[i];

  int count = 0;
  int canseeH = 0;
  for (int i = 0; i < N; i++){
    if (canseeH <= H[i]){
      count++;
      canseeH = H[i];
    }
  }

  cout << count << endl;
}