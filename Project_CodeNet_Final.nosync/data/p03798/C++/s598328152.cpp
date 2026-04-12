#include<cstdio>
int n;
char s[100005];
bool a[3], t[2];
int main(){
  scanf("%d %s", &n, s);
  for(int i = 0; i < n; i++) a[i%3] ^= s[i] == 'o';
  if(n%3 == 0 && (a[0] != a[1] || a[1] != a[2])){
    printf("-1");
    return 0;
  }
  t[0] = a[0]^a[n%3];
  t[1] = a[1]^a[(n-2)%3]^(s[0] == 'o');
  printf("%c%c", t[0] ? 'S' : 'W', t[1] ? 'S' : 'W');
  for(int i = 2; i < n; i++){
    t[i&1] = t[0]^t[1]^(s[i-1] == 'o');
    printf("%c", t[i&1] ? 'S' : 'W');
  }
}