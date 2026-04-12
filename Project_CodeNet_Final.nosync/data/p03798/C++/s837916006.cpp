#include <cstdio>

int main(void) {
  int N;
  scanf("%d", &N);
  char reply[N+2];
  scanf("%s", reply);
  reply[N] = reply[0];
  reply[N+1] = reply[1];
  
  int animal[N+2];
  for (int initial = 0; initial < 4; initial++) {
    // (0, 0), (1, 0), (0, 1), (1, 1)
    animal[0] = initial % 2;
    animal[1] = initial / 2;

    for (int i = 0; i < N; i++) {
      if (reply[i+1] == 'o') 
        animal[i+2] = animal[i+1] == 0 ? animal[i] : 1-animal[i];
      else
        animal[i+2] = animal[i+1] == 0 ? 1-animal[i] : animal[i];
    }
    if (animal[0] == animal[N] && animal[1] == animal[N+1]) {
      for (int j = 0; j < N; j++)
        printf("%c", animal[j] == 0 ? 'S' : 'W');
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
      
