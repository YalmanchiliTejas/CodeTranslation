#include <iostream>
using namespace std;

int main(){
  int n, a, b, c, tmp;
  int sum;
  string str;
  int i;

  while(cin>>n){
    if(n==0) break;
    sum=1; a=1; b=2, c=3;
    for(i=0; i<n; i++){
      cin>>str;
      switch(str[0]){
      case 'N':
        tmp=a; a=b; b=7-tmp; break;
      case 'S':
        tmp=a; a=7-b; b=tmp; break;
      case 'E':
        tmp=a; a=7-c; c=tmp; break;
      case 'W':
        tmp=a; a=c; c=7-tmp; break;
      case 'R':
        tmp=b; b=c; c=7-tmp; break;
      case 'L':
        tmp=b; b=7-c; c=tmp; break;
      }
      sum+=a;
    }
    printf("%d\n", sum);
  }

  return 0;
}