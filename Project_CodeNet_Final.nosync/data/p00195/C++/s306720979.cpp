#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n) 

int main(void){  
  int s1,s2;
  while(cin>>s1>>s2,s1||s2){
    int n[5] = {0}, mi = 0;
    n[0] = s1 + s2;
    FOR(i,1,5){
      cin >> s1 >> s2;
      n[i] = s1 + s2;
    }
    FOR(i,1,5){
      if(n[mi] < n[i] ) mi = i;
    }
    printf("%c %d\n",'A'+mi,n[mi]);
  }
  return 0;
}