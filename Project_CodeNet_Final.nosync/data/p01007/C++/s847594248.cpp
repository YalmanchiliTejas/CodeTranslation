#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[20][20], a_tmp[20][20];

void op0(){
  int r, c, size, angle;
  cin >> r >> c >> size >> angle;
  r--;
  c--;

  for(int q = 0; q < angle / 90; q++){
    memcpy(a_tmp, a, sizeof(a));

    for(int i = r; i < r + size; i++){
      for(int j = c; j < c + size; j++){
        int i0 = i - r;
        int j0 = j - c;
        a[r + j0][c + (size - i0 - 1)] = a_tmp[r + i0][c + j0];
      }
    }
  }
}

void op1(){
  int r, c, size;
  cin >> r >> c >> size;
  r--;
  c--;

  for(int i = r; i < r + size; i++){
    for(int j = c; j < c + size; j++){
      a[i][j] = !a[i][j];
    }
  }
}

void op2(){
  int r;
  cin >> r;
  r--;

  int left_val = a[r][0];
  for(int i = 0; i < n - 1; i++){
    a[r][i] = a[r][i + 1];
  }
  a[r][n - 1] = left_val;
}

void op3(){
  int r;
  cin >> r;
  r--;

  int right_val = a[r][n - 1];

  for(int i = n - 1; i > 0; i--){
    a[r][i] = a[r][i - 1];
  }
  a[r][0] = right_val;
}

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int r, int c, int val){
  a[r][c] = !a[r][c];

  for(int i = 0; i < 4; i++){
    int nr = r + dr[i];
    int nc = c + dc[i];

    if(nr < 0 || n <= nr || nc < 0 || n <= nc) continue;
    if(a[nr][nc] != val) continue;

    dfs(nr, nc, val);
  }
}

void op4(){
  int r, c;
  cin >> r >> c;
  r--;
  c--;
  dfs(r, c, a[r][c]);
}

int main(){
  int Q;

  while(cin >> n >> Q){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> a[i][j];
      }
    }

    while(Q--){
      int o;
      cin >> o;

      switch(o){
        case 0: op0(); break;
        case 1: op1(); break;
        case 2: op2(); break;
        case 3: op3(); break;
        case 4: op4(); break;
      }
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(j != 0) cout << " ";
        cout << a[i][j];
      }
      cout << endl;
    }
  }
}