#include<iostream>
using namespace std;

int n, h[100], ans = 1;
bool b = false;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(h[j] > h[i]){
        b = false;
        break;
      }
      b = true;
    }
    if(b)
    ans++;
  }

  cout << ans << endl;
  return 0;
}
