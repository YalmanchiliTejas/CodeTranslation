#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef  vector< vector<int> > vector2d;

int main() {

  string input;
  char color;
  int n,nblocks,movefrom,moveto;
  vector2d blocks; //blocks[山][色]とする
  cin >> n;
  blocks.reserve(n);
  
  while(1){
    cin >> input;
    if (input=="push"){
      cin >> nblocks >>color;
      blocks[nblocks-1].push_back(color);
    }else if (input=="pop"){
      cin >> nblocks;
      cout << (char)blocks[nblocks-1][blocks[nblocks-1].size()-1] <<endl;
      blocks[nblocks-1].pop_back();
    }else if (input=="move"){
      cin >> movefrom >> moveto;
      blocks[moveto-1].push_back(blocks[movefrom-1][blocks[movefrom-1].size()-1]);
      blocks[movefrom-1].pop_back();
    }else if (input=="quit")break;
  }
  return 0;
  
}