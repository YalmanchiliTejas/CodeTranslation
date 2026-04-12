#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int main(){

  int a,b,i = 0,z[100],m,n;
  
  while(1){
    int m = 0,n = 0;

    cin >> a >> b;
    if(a == 0 && b == 0 && i == 0) break;

    z[i] = a + b;
    i++;

    if(i == 5){
      for(i=0;i<5;i++){
	if(m < z[i]){
	  m = z[i];
	  n = i;
	}
      }
      printf("%c %d\n",'A'+n,m);
      i = 0;
    }
  }
}