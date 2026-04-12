#include<iostream>

using namespace std;

int main(){
  int n, cnt = 1;
  cin >> n;

  int h[n];
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 1; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(h[i] < h[j]) break;
      if(j == 0) cnt++;
    }
  }

  cout << cnt << endl;
}
