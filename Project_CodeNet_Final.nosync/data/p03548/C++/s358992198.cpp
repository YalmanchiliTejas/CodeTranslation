#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X, Y, Z;
  scanf("%d %d %d", &X,&Y,&Z);
  
  int i = 0;
  while(((Y+Z)*i+Z) <= X){
    i++;
  }
  cout << i-1;    
}