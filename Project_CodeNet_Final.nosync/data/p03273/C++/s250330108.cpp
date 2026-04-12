#include <stdio.h>

// 60min
int main(void){
  int h = 0, w = 0;
  char a[101][101];

  scanf("%d%d", &h, &w);

  for(int i = 0; i < h; i++){
    char tmp;
    scanf("%c", &tmp);
    for(int j = 0; j < w; j++){
      scanf("%c", &a[i][j]);
    }
  }
  while(1){
//    fprintf(stderr, "enter while()\n");
    int cnt = 0;
    // 全て白い行があるか
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
//        printf("i = %d j = %d a[i][j] = %c\n", i, j, a[i][j]);
        if(a[i][j] == '#'){
//          printf("break->\n");
          break;
        }else if(j == w - 1){
//          printf("aaaa\n");
          // 全て白い行だったので取り除く
          for(int k = i + 1; k < h; k++){
            for(int l = 0; l < w; l++){
             a[k - 1][l] =a[k][l];
            }
          }
          cnt++;
          h--;
        }
//        printf("ffffff2\n");
      }
//      printf("ffffff1\n");
    }

    // 全て白い列があるか
    for(int i = 0; i < w; i++){
      for(int j = 0; j < h; j++){
        if(a[j][i] == '#'){
          break;
        }else if(j == h - 1){
          // 全て白い列だったので取り除く
          for(int k = i + 1; k < w; k++){
            for(int l = 0; l < h; l++){
             a[l][k - 1] = a[l][k];
            }
          }
          cnt++;
          w--;
        }
      }
    }
//    fprintf(stderr, "last while()\n");

    if(cnt < 1){
      break;
    }
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  

  return 0;

}
