
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int H, W;
int counter;
vector< vector<bool> > field;


void solve();
void setup();

int main()
{
  setup();
  solve();
  return 0;
}

void setup() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W;
  field = vector<vector<bool>>(H, vector<bool>(W, false));
  counter = 0;
  REP(i, H) {
    string s;
    cin >> s;
    REP(j, W) {
      if (s[j] == '#') {
        counter++;
        field[i][j] = true;
      } else {
        field[i][j] = false;
      }
    }
  }
}

bool search(int row, int col) {
  if (row == H || col == W) { return false; }
  if (row == H - 1 && col == W - 1) { return true; }
  if (field[row][col] == false) { return false; }
  return search(row + 1, col) || search(row, col + 1);
}

void solve() {
  if (counter != (H + W - 1)) {
    cout << "Impossible" << endl;
    return;
  }
  bool result = search(0, 0);
  if (result) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

