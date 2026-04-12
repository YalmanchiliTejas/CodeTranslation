#include <iostream>
#include <algorithm>

#define FOR(i,l,n) for(int i=(l);i<(n);i++)
#define REP(i,n) FOR(i,0,n)
#define MAX_JUDGE 100
using namespace std;

int main(){
  int n,score[MAX_JUDGE];
  while(cin>>n,n){
    REP(i,n)cin>>score[i];
    sort(score,score+n);
    int sum=0;
    FOR(i,1,n-1)sum+=score[i];
    cout << sum/(n-2) <<endl;
  }
  return 0;
}

