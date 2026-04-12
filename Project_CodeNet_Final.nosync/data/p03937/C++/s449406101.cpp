#include <iostream>
#include <string>
using namespace std;

int main(void){
  int h, w;
  cin >> h >> w;
  string a[h];
  for(int i = 0; i < h; i++) cin >> a[i];
  int num = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] == '#') num++;
    }
  }
  if(num == h + w - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
