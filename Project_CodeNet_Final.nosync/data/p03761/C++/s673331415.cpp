#include <stdio.h>
int main(void){
  int n,i,j,a[50][26]={},ans[26]={},min;
  char s[51];
  scanf("%d\n",&n);
  for (i=0;i<n;i++){
    scanf("%s",s);
    for (j=0;s[j];j++) a[i][(int)s[j]-97]++;
  }
  for (i=0;i<26;i++){
    min=50;
    for (j=0;j<n;j++){
      if (a[j][i]==0){
        ans[i]=0;
        break;
      }
      if (min>a[j][i]) min=a[j][i];
    }
    if (j==n) ans[i]=min;
  }
  for (i=0;i<26;i++){
    if (ans[i]){
      for (;ans[i]>0;ans[i]--) printf("%c",(char)(i+97));
    }
  }
  printf("\n");
  return 0;
}