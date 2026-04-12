#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

int main(){
  int H,W;
  vector<string> a;
  cin >> H >> W;
  char board[H][W];
  for(int i = 0; i < H; i ++){
    for(int j = 0 ; j < W; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < H; i ++){
    for(int j = 0 ; j < W; j++){
      if(board[i][j] == '.') continue;
      else{
        string s = "";
        for(int k = 0; k < W; k++){
          s = s + board[i][k];
        }
        a.push_back(s);
        break;
      }
    }
  }


  for(int j = 0 ; j < W; j++){
    for(int i = 0; i < a.size(); i++){
      if(a[i][j] == '.' && i == a.size()-1){
        for(int k = 0; k < a.size(); k++) a[k][j] = 'x';
      }
      else if(a[i][j] == '.') continue;
      else break;
    }
  }
  
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < W; j++){
      if(a[i][j] != 'x') cout << a[i][j] ;
    }
      cout << endl;
  }

  return 0;
}
