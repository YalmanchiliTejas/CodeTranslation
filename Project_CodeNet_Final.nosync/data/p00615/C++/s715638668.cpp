#include<cstdio>
#include<algorithm>
int main(void){
  int n, m, k, t[20100];
  for( ; ; ){
    scanf("%d %d", &n, &m);
    if(!(n + m)) break;
    for(int i = 0;i < n + m; i++) scanf("%d", t + i);
    std::sort(t, t + n + m);
    k = t[0];
    for(int i = 0;i < n + m - 1; i++)
      k = std::max(t[i + 1] - t[i], k);
    printf("%d\n", k);
  }
}
