#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  int cnt = 0;
  int hei = 0;
  for (int j = 0; j < n; j++){
    if (hei <= h[j]){
      cnt += 1;
      hei = h[j];
    }
  }
  cout << cnt << endl;
  return 0;
}