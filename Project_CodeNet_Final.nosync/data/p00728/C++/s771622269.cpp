#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define INF 1e9

int n,score[111],ave;

void solve(){
  ave = 0;
  cin>>n;

  if(n == 0) exit(0);

  REP(i,n){
    cin>>score[i];
  }

  sort(score,score+n);

  FOR(i,1,n-1){
    ave += score[i];
  }
  ave /= (n-2);

  cout<<ave<<endl;
}


int main(){

  while(1){
    solve();
  }

  return 0;
}
