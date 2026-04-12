#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX_N 100000
int  n, i,  j, ans, c[MAX_N];

int sort(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int main(){
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    for(i = 0; i < n; i++) {
      scanf("%d", &c[i]);
      if(i % 2 == 1 && c[i] != c[i - 1]){
	for(j = i - 1; j >= 0; j--){
	  if(c[i] == c[j]) break;
	  c[j] = c[i];
	}
      }
    }
      ans = n;
      for(i = 0; i < n; i++) ans -= c[i];
      printf("%d\n", ans);
  }
  return 0;
}