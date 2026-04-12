#include<cstdio>
int n, i, j;
char s[100005];
bool a[4][100005];
int main(){
  scanf("%d %s", &n, s);
  a[1][0] = a[2][1] = a[3][0] = a[3][1] = true;
  for(i = 1; i < n; i++) for(j = 0; j < 4; j++)
    a[j][i+1] = a[j][i]^a[j][i-1]^s[i] == 'o';
  for(j = 0; j < 4; j++){
    if(a[j][n] == a[j][0] && a[j][n-1] == a[j][0]^a[j][1]^s[0] == 'o'){
      for(i = 0; i < n; i++) printf("%c", a[j][i] ? 'S' : 'W');
      return 0;
    }
  }
  printf("-1");
}
