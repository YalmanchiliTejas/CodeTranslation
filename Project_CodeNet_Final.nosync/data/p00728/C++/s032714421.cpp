#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX_N 100
int  n, i, judge[MAX_N], ans;

int sort(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int main(){
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    for(i = 0; i < n; i++) scanf("%d", &judge[i]);
    qsort(judge, n, sizeof(int), sort);
    ans = 0;
    for(i = 1; i < n - 1; i++) ans += judge[i];
    printf("%d\n", ans / (n - 2));
  }
  return 0;
}