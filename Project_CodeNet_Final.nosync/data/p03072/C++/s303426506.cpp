#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n, h[20];
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &h[i]);
  
  int result = 1;
  for(int i=1; i<n; i++){
    int flag = 1;
    for(int j=0; j<i; j++){
    	if(h[j] > h[i]) {
          flag = 0;
          break;
        }
    }
    result += flag;
  }
  
  printf("%d\n", result);
  return 0;
}