#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  int FUJI = 0;
  int COUNT = 0;
  for (int i = 0; i < N; i++){
    cin >> H.at(i);
    if (FUJI <= H.at(i)){
    FUJI = H.at(i);
      COUNT++;
    }
    }
   cout << COUNT << endl;   
}