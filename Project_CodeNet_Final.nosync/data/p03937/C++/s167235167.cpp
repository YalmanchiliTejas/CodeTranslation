#include <iostream>
#include <string>

using namespace std;

int h, w, flg = true, cnt = 0;
string *lines;

bool resolve(int y, int x){
  if(!flg) return false;
  if(y >= h || x >= w || lines[y][x] == '.') return false;
  else if(y == h - 1 && x == w - 1) return true;
  if(!(resolve(y + 1, x) ^ resolve(y, x + 1))) flg = false;
  cnt++;
  return true;
}

int main(){
  cin >> h >> w;
  lines = new string[h];
  for(int i = 0; i < h; i++) cin >> lines[i];
  resolve(0, 0);
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(lines[i][j] == '#') cnt--;
  cout << (flg && !++cnt? "Possible" : "Impossible") << endl;
  delete[] lines;
}
