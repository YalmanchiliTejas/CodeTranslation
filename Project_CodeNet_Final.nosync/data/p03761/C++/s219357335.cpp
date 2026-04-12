#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int n;
  cin>>n;
  int m[n][26];
  REP(i,n)REP(j,26)m[i][j]=0;
  REP(i,n){
    string S;
    cin>>S;
    for(char c:S){
      m[i][c-'a']++;
    }
  }
  int ma[26];
  REP(c,26){
    int min=9999;
    REP(i,n){
      if(m[i][c]<min)min=m[i][c];
    }
    ma[c]=min;
  }
  REP(c,26){
    REP(i,ma[c])cout<<char(c+'a');
  }
  cout<<endl;
  return 0;
}
