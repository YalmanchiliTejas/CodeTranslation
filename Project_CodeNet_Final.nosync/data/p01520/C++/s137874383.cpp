#define REP(i,n) for(int i=0; i<(int)(n); i++)
 
#include <queue>
#include <set>
#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }
 
using namespace std;
 
int main(){
  const int n = getInt();
  const int t = getInt();
  const int e = getInt();
 
  REP(i,n){
    const int x = getInt();
 
    REP(j,t + 1){
      const int xx = x * j;
      if(t - e <= xx && xx <= t + e){
        printf("%d\n", i + 1);
        return 0;
      }
      if(t + e < xx) break;
    }
  }
 
  puts("-1");
 
  return 0;
}