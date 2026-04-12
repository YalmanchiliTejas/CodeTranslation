#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
  int n, t, e;
  cin >> n >> t >> e;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int a = 0;
  for (int i = 0; i < n; i++) {
    while(1){
      if(t - e <= a*x[i] && a*x[i] <= t + e){
        std::cout << i + 1 << std::endl;
        return 0;
      }
      else a++;
      if(a*x[i] > t + e){
       a = 1;
       break; 
      }
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}