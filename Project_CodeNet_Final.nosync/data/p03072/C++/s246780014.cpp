#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0;
  cin >> n;
  vector<int>data(n);
  for(int i = 0;i < n;i++){
    cin >> data.at(i);
  }
  for(int i = 1;i < n;i++){
    for(int j = 0;j < i;j++){
      if(data.at(j) > data.at(i)){
        break;
      }
      else if(j == i-1){
        ans++;
      }
    }
  }
  cout << ans+1 << endl;
}