#include <iostream>
#include <stdio.h>

#define rep(i,min,sup) for(int i=min;i<sup;i++)
#define per(i,min,sup) for(int i=(sup-1);i>=min;i--)
#define swap(a,b) {a+=b;b=a-b;a-=b;}
#define ll long long

using namespace std;

main(){
  char c[3];
  scanf("%c%c%c",&c[0],&c[1],&c[2]);
  if(c[0]==c[1]&&c[1]==c[2])printf("No");
  else printf("Yes");
}