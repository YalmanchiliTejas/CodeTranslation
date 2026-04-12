#include <cstdio>

int p[200010], r[200010];

int main(){
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &p[i]);

  int s = 1, e = N; bool v = true;

  for(int i = N; i >= 1; i--){
    r[v ? s : e] = p[i];
    if(v) s++; else e--;
    v = !v;
  }

  for(int i = 1; i <= N; i++) printf("%d ", r[i]);
  printf("\n");
  return 0;
}