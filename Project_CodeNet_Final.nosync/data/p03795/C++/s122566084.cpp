#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define INF 1e9

int main(){
  int N,x,y;
  cin>>N;

  x = N*800;
  y = N/15*200;

  cout<<x-y;

  return 0;
}