#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector <string> a(H);
  for (int i = 0; i < H; i++) {
	  cin >> a[i];
	}
  vector <int> r;
  vector <int> c;
  for (int i = 0; i < H; i++) {
	  bool flag = false;
	  for (int j = 0; j < W; j++) {
		  if (a[i][j] == '#') {
			  flag = true;
			  break;
			}
		}
	  if (flag) {
		  r.push_back(i);
		}
	}
  for (int j = 0; j < W; j++) {
	  bool flag = false;
	  for (int i = 0; i < H; i++) {
		  if (a[i][j] == '#') {
			  flag = true;
			  break;
			}
		}
	  if (flag) {
		  c.push_back(j);
		}
	}
  for (auto itr1 = r.begin(); itr1 != r.end(); itr1++) {
	  for (auto itr2 = c.begin(); itr2 != c.end(); itr2++) {
		  cout << a[*itr1][*itr2];
		}
	  cout << endl;
	}
  return 0;
}
