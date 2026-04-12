#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define INF 1e9

int main(){
  int X,Y,Z;

  cin>>X>>Y>>Z;

  cout<<(X-Z)/(Y+Z)<<endl;

  return 0;
}
