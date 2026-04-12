#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> s;
typedef long long int ll;

int abs(int x){
  return x > 0 ? x : -x;
}

int length(char c[]){
  int cnt=0;
  for(cnt=0;c[cnt]!='\0';cnt++){
  }
  return cnt;
}


int x,y,z;

int main(){
  scanf("%d %d %d", &x,&y,&z);
  x-=z;
  printf("%d\n",x/(y+z));
}
