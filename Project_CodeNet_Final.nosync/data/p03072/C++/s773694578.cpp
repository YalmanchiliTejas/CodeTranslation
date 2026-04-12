#include <cstdio>
int main() {
  int N;
  int view = 0;
  int max = 0;
  scanf("%d", &N);
  int H[N];
  for(int i = 0; i < N; i++){
    scanf("%d", &H[i]);
    if(H[i] > max){
      max = H[i];
    }
    if(H[i] >= max){
      view += 1;
    }
  }
  
  printf("%d\n", view);
  return 0;
}
