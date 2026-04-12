#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int big = 0, count = 0, a;
  for(int i = 0; i < N; i++){
    cin >> a;
    if(a >= big){
      count++;
      big = a;
    }
  }
  cout << count << endl;
  return 0;
}