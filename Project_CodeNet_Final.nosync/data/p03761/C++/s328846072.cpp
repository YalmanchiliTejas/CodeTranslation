#include<cstdio>

char a = 'a';//97
int n;
char str[50][52];
int az[26][50] = {};
int m;
int min = 99;
char ans[52];
int set = 0;

int main(){

  scanf("%d", &n);
  for(int l = 0; l < n; l++){
    scanf("%s", str[l]);
    m = 0;
    while(str[l][m] != '\0'){
      az[(int)str[l][m] - 97][l]++;
      m++;
    }
  }

  for(int l = 0; l < 26; l++){
    for(m = 0; m < n; m++){
      if(min > az[l][m]) min = az[l][m];
    }
    for(m = 0; m < min; m++){
      ans[set] = (char)(l+97);
      set++;
    }
    min = 99;
  }
  ans[set] = '\0';

  printf("%s", ans);

  return 0;
}
