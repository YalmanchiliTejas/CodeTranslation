#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N; 
  cin >> N;
  int max = 0; 
  int count = 0;
  for(int i = 0; i < N; i++){
    int H;
    cin >> H;
    if(H >= max){
      max = H;
      count++;  
    } 
  }
  cout << count <<endl;
}