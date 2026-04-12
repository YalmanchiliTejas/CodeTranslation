#include<cstdio>
int n;
char s[100005];
bool a[3], t[2];
int main(){
  scanf("%d %s", &n, s);
  for(int i = 0; i < n; i++) a[i%3] ^= s[i] == 'o';
  if(n%3 == 0 && !(a[0] == a[1] && a[1] == a[2])) printf("-1");
  else for(int i = 0; i < n; i++){
    if(i < 2) t[i] = a[i]^a[(n+i)%3]^(i && s[0] == 'o');
    else t[i&1] = t[0]^t[1]^(s[i-1] == 'o');
    printf("%c", t[i&1] ? 'S' : 'W');
  }
}
