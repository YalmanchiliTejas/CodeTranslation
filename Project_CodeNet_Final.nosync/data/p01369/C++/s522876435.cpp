#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;
vector<char> aleft(15);
int main(){
  aleft[0]='q'; aleft[1]='w'; aleft[2]='e'; aleft[3]='r'; aleft[4]='t';
  aleft[5]='a'; aleft[6]='s'; aleft[7]='d'; aleft[8]='f'; aleft[9]='g';
  aleft[10]='z'; aleft[11]='x'; aleft[12]='c'; aleft[13]='v'; aleft[14]='b';
  char str[64];
  while(scanf("%s", str) && str[0] != '#'){
    bool f = 0;
    int res = 0;
    if(find(aleft.begin(), aleft.end(), str[0]) == aleft.end()) f = 1;
    REP(i, 1, strlen(str)){
      if((find(aleft.begin(), aleft.end(), str[i]) == aleft.end()) != f){ res++; f = (f+1)%2;}
    }

    printf("%d\n", res);
  }
  return 0;
}