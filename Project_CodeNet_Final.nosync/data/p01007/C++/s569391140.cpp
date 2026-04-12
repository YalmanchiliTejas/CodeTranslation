#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 15
int n, m, a[MAX_N][MAX_N];
void Rotate( int r, int c, int& size){
  int next[size][size];
  for(int i = 0 ; i < size ; i++ ){
    for(int j = 0 ; j < size ; j++ ){
      next[i][j] = a[r + size - j - 1][c + i];
    }
  }
  for(int i = 0 ; i < size ; i++ ){
    for(int j = 0 ; j < size ; j++ ){
      a[r + i][c + j] = next[i][j];
    }
  }
}
void Reversal(int r,int c,int &size){
  for(int i  = 0 ; i < size ; i++ ){
    for(int j = 0 ; j < size ; j++ ){
      a[r + i][c + j] = !a[r + i][c + j];
    }
  }
}
void Left_shift( int r){
  rotate( a[r], a[r] + 1, a[r] + n);
}
void Right_shift( int r){
  rotate( a[r], a[r] + n - 1, a[r] + n);
}
static const int dy[] = { 1, 0, -1, 0}, dx[] = { 0, 1, 0, -1};
bool used[15][15];
void Island_revesal( int y, int x){
  if(used[y][x]++) return;
  a[y][x] = !a[y][x];
  for(int i = 0 ; i < 4 ; i++ ){
    int ny = y + dy[i], nx = x + dx[i];
    if( ny >= 0 && ny < n && nx >= 0 && nx < n && a[ny][nx] != a[y][x]){
      Island_revesal( ny, nx);
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++ ){
    for(int j = 0 ; j < n ; j++ ){
      cin >> a[i][j];
    }
  }
  while( m-- ){
    int o;
    cin >> o;
    if(o == 0){
      int r, c, size, angle;
      cin >> r >> c >> size >> angle;
      for(int i = 0 ; i < angle ; i += 90 ) Rotate( r - 1, c - 1, size);
    }else if(o == 1){
      int r, c, size;
      cin >> r >> c >> size;
      Reversal( r - 1, c - 1, size);
    }else if(o == 2){
      int r;
      cin >> r;
      Left_shift( r - 1);
    }else if(o == 3){
      int r;
      cin >> r;
      Right_shift( r - 1);
    }else{
      int r, c;
      for(int i = 0 ; i < n ; i++ )
        for(int j = 0 ; j < n ; j++ ) used[i][j] = false;
      cin >> r >> c;
      Island_revesal( r - 1, c - 1);
    }
  }
  for(int i = 0 ; i < n ; i++ ){
    for(int j = 0 ; j < n ; j++ ){
      cout << (j ? " " : "") << a[i][j];
    }
    cout << endl;
  }
}