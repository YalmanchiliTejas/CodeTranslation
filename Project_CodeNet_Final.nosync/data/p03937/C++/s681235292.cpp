#include <cstdio>
using namespace std;

const int MAXN = 10;

int N, M;
char mat[MAXN][MAXN];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%s", mat[i]);
  
  int pos = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < pos; j++)
      if (mat[i][j] == '#') {
        puts("Impossible");
        return 0;
      }
    if (mat[i][pos] !=  '#') {
      puts("Impossible");
      return 0;
    }
    for (; pos < M && mat[i][pos] == '#'; pos++);
    pos--;
    for (int j = pos + 1; j < M; j++)
      if (mat[i][j] == '#') {
        puts("Impossible");
        return 0;
      }
  }
  
  puts("Possible");
  
  return 0;
}