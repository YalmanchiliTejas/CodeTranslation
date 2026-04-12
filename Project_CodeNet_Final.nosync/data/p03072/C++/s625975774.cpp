#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> hotel(N);
  int cnt = N;
  for (int i = 0; i < N; i++){
    cin >> hotel.at(i);
  }
  for (int i = 0; i < N; i++){
    for (int j = 0; j < i; j++){
      if(hotel.at(i) < hotel.at(j)){
        cnt--;
        break;
      }
    }
  }
  cout << cnt << endl;
}
