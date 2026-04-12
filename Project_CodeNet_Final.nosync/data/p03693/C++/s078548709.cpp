#include <cstdio>

int main() {
int a, b, c; scanf("%d%d%d", &a, &b, &c);
int v = 10*b + c;
if(v % 4 == 0) {
printf("YES\n");
}
else {
printf("NO\n");
}
return 0;
}