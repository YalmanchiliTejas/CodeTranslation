#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
  const char *left = "qwertasdfgzxcvb";
  int hand[128];
  char buff[64];
  REP(i, 128) hand[i] = 0;
  REP(i, strlen(left)) hand[left[i]] = 1;

  while(scanf("%s", buff), buff[0] != '#'){
    int len = strlen(buff);
    int ans = 0;

    REP(i, len - 1) ans += abs(hand[buff[i]] - hand[buff[i+1]]);

    printf("%d\n", ans);
  }

  return 0;
}