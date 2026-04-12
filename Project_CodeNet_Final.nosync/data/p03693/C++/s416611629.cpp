#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b;
  scanf("%d%d%d",&r,&g,&b);
  printf("%s\n",(r*100+g*10+b)%4==0?"YES":"NO");
}
