#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int n;
  int score;
  while(cin >> n && n){
    int lc = 1000;
    int uc = 0;
    score = 0;
    for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      score += num;
      lc = min(lc, num);
      uc = max(uc, num);
    }
    cout << (score - uc - lc) / (n - 2) << endl;
  }
  return 0;
}