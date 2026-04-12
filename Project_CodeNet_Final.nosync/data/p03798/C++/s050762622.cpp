#include <cstdio>

int main(void) {
  int N;
  scanf("%d", &N);
  char reply[N+2];
  scanf("%s", reply);
  reply[N] = reply[0]; reply[N+1] = reply[1];// reply N, N+1を忘れないように
  
  int animal[N+2];

  for (int initial = 0; initial < 4; initial++) {
    animal[0] = initial / 2;
    animal[1] = initial % 2;

    for (int i = 0; i < N; i++) {
      if (animal[i+1] == 0) {
        if (reply[i+1] == 'o') animal[i+2] = animal[i]; 
        else animal[i+2] = 1-animal[i];
      } else {
        if (reply[i+1] == 'o') animal[i+2] = 1-animal[i];
        else animal[i+2] = animal[i];
      }
    }
    if (animal[0] == animal[N] && animal[1] == animal[N+1]) {
      for (int j = 0; j < N; j++) {
        if (animal[j] == 0) printf("S");
        else printf("W");
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
 
