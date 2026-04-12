#include <iostream>
#include <algorithm>
#define SIZE 10
using namespace std;

class State{
public:
  int data[SIZE][SIZE];
  int put[SIZE][SIZE];
  State() {
    fill((int*)put, (int*)put+SIZE*SIZE, 0);
  }
  void puts(int x, int y) {
    static int d[5][2] = {{0,-1},{1,0},{0,1},{-1,0},{0,0}};
    put[y][x] = 1;
    for(int k = 0; k < 5; k++) {
      int nx = x + d[k][0];
      int ny = y + d[k][1];
      if(nx < 0 || nx >= SIZE) continue;
      if(ny < 0 || ny >= SIZE) continue;
      data[ny][nx] = -(data[ny][nx] - 1);
    }
  }
  bool isAll0() {
    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
	if(data[i][j] != 0) return false;
      }
    }
    return true;
  }
  void show() {
    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
	if(j != 0) cout << ' ';
	cout << put[i][j];
      }
      cout << endl;
    }
  }
};

bool rec(State s, int x, int y) {
  static int d[5][2] = {{0,-1},{1,0},{0,1},{-1,0},{0,0}};
  if(s.isAll0()) {
    s.show();
    return true;
  }

  for(int i = y; i < SIZE; i++) {
    int j;
    if(i == y) j = x;
    else       j = 0;
    for(; j < SIZE; j++) {
      bool flag = false;
      /*for(int k = 0; k < 5; k++) {
	int nx = j + d[k][0];
	int ny = i + d[k][1];
	if(nx < 0 || nx >= SIZE) continue;
	if(ny < 0 || ny >= SIZE) continue;
	if(s.data[ny][nx] == 1) {
	  flag = true;
	  break;
	}
	}*/
      flag = true;
      if(flag) {
	if(i > 0 && s.data[i-1][j] == 0) continue;
	State tmp = s;
	tmp.puts(j, i);
	int nx, ny;
	nx = j + 1;
	ny = i;
	if(nx >= SIZE) {
	  nx = 0;
	  ny++;
	}
	if(rec(tmp, nx, ny)) {
	  return true;
	}
	if(i > 0 && s.data[i-1][j] == 1) return false;
      }
    }
  }
  return false;
}

main() {
  int n;
  cin >> n;
  for(int t = 0; t < n; t++) {
    State s;
    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
	cin >> s.data[i][j];
      }
    }
    rec(s, 0, 0);
  }
}