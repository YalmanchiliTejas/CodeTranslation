#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string>data(h);
  vector<int>left(h);
  vector<int>right(h);
  for(int i = 0;i < h;i++) cin >> data[i];
  for(int i = 0;i < h;i++){
    bool flag = true;
    for(int j = 0;j < w;j++){
      if(data[i][j] == '#'){
        if(flag){
          left[i] = j;
          flag = false;
        }
        right[i] = j;
      }
    }
  }
  for(int i = 0;i < h-1;i++){
    if(right[i] != left[i+1]){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  return 0;
}
