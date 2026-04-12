#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

char ansbuff[300];
char *ans;
int maxlen;

void max_substr(char *s1, char *s2, int l1, int l2){
  static int dp[330][330];
  REP(i,l1+1) REP(j,l2+1) dp[i][j] = 0;  
  REP(i,l1) REP(j,l2){
    if(s1[i] == s2[j]){
      dp[i+1][j+1] = dp[i][j] + 1;
    }
    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
  }
  REP(i,l1) dp[i+1][l2] = max(dp[i+1][l2], dp[i][l2]);
  REP(j,l2) dp[l1][j+1] = max(dp[l1][j+1], dp[l1][j]);
  
  if(maxlen < dp[l1][l2]){
    int p1 = l1;
    int p2 = l2;
    ans = ansbuff + sizeof(ansbuff) - 1;

    maxlen = dp[l1][l2];

    while(p1 != 0 || p2 != 0){
      if(p1 != 0 && dp[p1-1][p2] == dp[p1][p2]){
	p1 = p1 - 1;
      }else if(p2 != 0 && dp[p1][p2-1] == dp[p1][p2]){
	p2 = p2 - 1;
      }else{
	assert(p1 != 0 && p2 != 0);
	*--ans = s1[p1-1];
	p1 = p1 - 1;
	p2 = p2 - 1;
      }
    }

    /*
    REP(i, l1) putchar(s1[i]);
    printf(" ");
    REP(i, l2) putchar(s2[i]);
    printf(" : %s\n", ans);
    */
  }
}

int main(){
  char buff[330];

  while(scanf("%s", buff), buff[0] != '#'){
    int len = strlen(buff);
    char *str1 = buff;

    maxlen = 0;
    for(char *str2 = buff + 1; *str2 != '\0'; str2++){
      int len1 = (int)(str2 - str1);
      int len2 = (int)(len  - len1);

      max_substr(str1, str2, len1, len2);
    }
    
    puts(ans);
  }

  return 0;
}