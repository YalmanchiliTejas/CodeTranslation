#include <bits/stdc++.h>
using namespace std;

int N, M;
char inp[10];

int main() {
   scanf("%d%d", &N, &M);
   int cc = 0;
   for(int i = 0; i < N; i++) {
      scanf("%s", inp);
      cc += count(inp, inp + M, '#');
   }
   if(cc == N+M-1) printf("Possible\n");
   else printf("Impossible\n");
}
