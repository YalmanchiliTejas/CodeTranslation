#include<cstdio>
#include<iostream>

using namespace std;

int a,b;
int main(){
  scanf("%d %d",&a,&b);
  if(a > b)
    puts("a > b");
  else if(a < b)
    puts("a < b");
  else{
    puts("a == b");
  }
  return 0;
}