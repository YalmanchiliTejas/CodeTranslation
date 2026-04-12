#include<stdio.h>

int main(){
  int h, w;

  scanf("%d %d", &h, &w);

  char a[h+1][w+1];
  int i, j;

  for(i = 0; i < h; i++){
    scanf("%s", a[i]);
  }

  /*  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      printf("%c", a[i][j]);
    }
    printf("\n");
    }*/

  int tate[h], yoko[w];
  int tate_count, yoko_count;

  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(a[i][j] == '.'){
	yoko_count++;
      }
    }
    //printf("%d\n", yoko_count);
    if(yoko_count > 0 && yoko_count == w){
      yoko[i] = 1;
    }
    else{
      yoko[i] = 0;
    }
    yoko_count = 0;
  }

  for(j = 0; j < w; j++){
    for(i = 0; i < h; i++){
      if(a[i][j] == '.'){
	tate_count++;
      }
    }
    //printf("%d\n", tate_count);
    if(tate_count > 0 && tate_count == h){
      tate[j] = 1;
    }
    else{
      tate[j] = 0;
    }
    tate_count = 0;
  }

  int check = 0;

  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(yoko[i] == 0 && tate[j] == 0){
	printf("%c", a[i][j]);
	check = 1;
      }
    }
    if(check == 1){
      check = 0;
      printf("\n");
    }
  }
  
  return 0;
}