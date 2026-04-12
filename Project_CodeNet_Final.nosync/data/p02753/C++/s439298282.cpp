#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

int main(){
  std::string S;
  std::cin >> S;
  if ((S[0]==S[1]) && (S[0]==S[2])){
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}
