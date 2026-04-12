#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n, m, a, b;
  cin >> n >> m;
  bool ma[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      ma[i][j] = false;
  for(int i = 0; i  < m; i++){
    cin >> a >> b;
    ma[a - 1][b - 1] = true;
    ma[b - 1][a - 1] = true;
  }
  int p[n];
  int ans = 0;
  for(int i = 0; i < n; i++) p[i] = i;
  do{
    bool flag = true;
    for(int i = 0; i < n - 1; i++){
      if(p[0] != 0) flag = false;
      if(!ma[p[i]][p[i + 1]]) flag = false;
    }
    if(flag) ans++;
  }while(next_permutation(p, p + n));
  cout << ans << endl;
  return 0;
}
