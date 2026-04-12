#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
  	for (int j = 0; j < W; j++)
    {
    	cin >> a.at(i).at(j);
    }
  }
  vector<char> row_white(H, '.');
  vector<char> row_black(H, '#');
  vector<char> column_white(W, '.');
  vector<char> column_black(W, '#');
  bool flag = true;
  for (int i = 0; i < H; i++)
  {
    if (a.at(i) == column_white) continue;
  	for (int j = 0; j < W; j++)
    {
      	for (int k = 1; k < H; k++)
        {
        	if (a.at(k).at(j) != a.at(k-1).at(j)) break;
          	if (a.at(k).at(j) == '.' && k == H - 1) flag = false;
        }
      	if (flag) cout << a.at(i).at(j);
      	flag = true;
    }
    cout << endl;
  }
}