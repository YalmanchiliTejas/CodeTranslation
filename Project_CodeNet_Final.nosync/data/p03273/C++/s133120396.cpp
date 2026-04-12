#include <iostream>

using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  char GRID[100][100];
  bool is_all_white_H[100];
  bool is_all_white_W[100];
  
  for (int h=0; h<H; ++h) {
    for (int w=0; w<W; ++w) {
      cin >> GRID[h][w];
    }
  }

  for (int h=0; h<H; ++h) {
    is_all_white_H[h] = true;
    for (int w=0; w<W; ++w) {
      if (GRID[h][w]=='#') {
	is_all_white_H[h] = false;
	break;
      }
    }
  }

  for (int w=0; w<W; ++w) {
    is_all_white_W[w] = true;
    for (int h=0; h<H; ++h) {
      if (GRID[h][w]=='#') {
	is_all_white_W[w] = false;
	break;
      }
    }
  }

  for (int h=0; h<H; ++h) {
    if (is_all_white_H[h])
      continue;
    for (int w=0; w<W; ++w) {
      if (is_all_white_W[w])
	continue;
      cout << GRID[h][w];
    }
    cout << endl;
  }


  return 0;
}