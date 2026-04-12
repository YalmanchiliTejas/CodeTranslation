#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
  int h, w, cnt = 0;
  string line;
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    cin >> line;
    for(int j = 0; j < w; j++) if(line[j] == '#') cnt++;
  }
  cout << (h + w - 1 - cnt ? "Impossible" : "Possible") << endl;
}