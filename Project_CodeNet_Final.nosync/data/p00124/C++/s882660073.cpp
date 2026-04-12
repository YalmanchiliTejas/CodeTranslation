#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define MP make_pair

int main(){
  pair<int,int> data[10];
  char team[10][21];
  int n,d=0;
  while(cin>>n,n){
    if(d!=0)cout<<endl;
    d=1;
    REP(i,n){
      string s;
      int a,b,c;
      cin>>team[i]>>a>>b>>c;
      data[i]=MP(-(a*3+c),i);
    }
    sort(data,data+n);
    REP(i,n){
      cout<<team[data[i].second]<<","<<-data[i].first<<endl;
    }
  }
  
}