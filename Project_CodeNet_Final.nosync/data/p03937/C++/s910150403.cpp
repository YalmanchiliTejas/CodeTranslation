#include <bits/stdc++.h>
using namespace std;
int H, W, totalPass = 0;
bool possible = false;
vector<vector<bool>> Passed(8, vector<bool>(8, false));

void search(int x, int y, int cnt)
{
  if (x < 0 || x >= W || y < 0 || y >= H)
    return;
  if (Passed.at(y).at(x) = false)
    return;
  if (x == W - 1 && y == H - 1 && cnt == totalPass - 1)
  {
    possible = true;
    return;
  }
  search(x + 1, y, cnt + 1); // 右へ
  search(x, y + 1, cnt + 1); // 下へ
}

int main()
{
  char c;
  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      if (c == '#')
      {
        Passed.at(i).at(j) = true;
        totalPass++;
      }
    }
  }
  search(0, 0, 0);
  cout << (possible ? "Possible" : "Impossible") << endl;
}
