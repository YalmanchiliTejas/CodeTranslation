#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int h;
  cin >> h;
  int hmax = h;
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    cin >> h;
    if (h >= hmax){
      hmax = h;
      cnt++;
    };
  }
  cout << cnt << endl;
}