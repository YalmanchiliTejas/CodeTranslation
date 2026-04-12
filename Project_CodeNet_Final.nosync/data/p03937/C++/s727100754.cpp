#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<int>min(h,-1);
  vector<int>max(h,-1);
  for(int i = 0;i < h;i++){
    bool minf = true;
    for(int j = 0;j < w;j++){
      char a;
      cin >> a;
      if(a == '#'){
        if(minf){
          min[i] = j;
          minf = false;
        }
        max[i] = j;
      }
    }
  }
  if(min[0] == -1){
    cout << "Impossible" << endl;
    return 0;
  }
  for(int i = 1;i < h;i++){
    if(min[i] == -1){
      cout << "Impossible" << endl;
      return 0;
    }
    if(max[i-1] > min[i]){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}
