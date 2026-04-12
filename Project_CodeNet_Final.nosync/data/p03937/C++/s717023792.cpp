#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int H, W;
bool is_ok(vector<string> field)
{
  stack<pair<int, int>> pos_stack;
  pos_stack.push(make_pair(0, 0));
  int dirx[] = {1, 0};
  int diry[] = {0, 1};
  field[0][0] = 'o';
  while (pos_stack.size())
  {
    pair<int, int> pos = pos_stack.top();
    pos_stack.pop();
    int pos_x = pos.first;
    int pos_y = pos.second;

    rep(i, 2)
    {
      int next_x = pos_x + dirx[i];
      int next_y = pos_y + diry[i];

      if (0 <= next_x && next_x < H + 1 && 0 <= next_y && next_y < W + 1 && field[next_x][next_y] == '#')
      {
        field[next_x][next_y] = 'o';
        pos_stack.push(make_pair(next_x, next_y));
        break;
      }
    }
  }

  rep(i, H) rep(j, W)
  {
    if (field[i][j] == '#')
      return false;
  }
  return true;
}

int main()
{
  cin >> H >> W;
  vector<string> A(H);
  rep(i, H)
  {
    cin >> A[i];
  }
  A.push_back(string(W, '.'));
  if (is_ok(A))
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}