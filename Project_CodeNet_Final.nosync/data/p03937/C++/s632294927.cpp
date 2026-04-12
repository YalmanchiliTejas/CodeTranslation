#include <iostream>
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  char A[H][W];
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      cin >> A[i][j];
  }
  int cnt = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (A[i][j] == '#')
        cnt++;
    }
  }
  cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << endl;
  return 0;
}