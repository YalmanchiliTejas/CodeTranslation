#include <stdio.h>  /*入出力*/
#include <stdlib.h> /*標準ライブラリ*/
#include <string.h> /*文字列*/
#include <math.h>   /*計算*/
#include <assert.h> /*確認*/
#include <ctype.h>  /*文字操作*/
#include <stdbool.h>/*bool型の利用*/

#define rep(i, n) for(int  i = 0; i < (n); i++)
#define max(a,b) ((a>b)?a:b)
#define ABS(a) (((a)>(0))?a:-(a))

//date 03/07
//abc158

int main(void)
{
  char s[3];
  char *a= "AAA";
  char *b="BBB";
  bool flag = true;
    scanf("%s", &s);
  if (strcmp(s,a) == 0 || strcmp(s,b) == 0) {
    printf("No\n" );
  }else printf("Yes\n" );
  return 0;
}
