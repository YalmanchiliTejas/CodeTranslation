#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
  vector<pair<int, int> > team;
  map<int,int> rank;
  int a,b;
  while(scanf("%d,%d",&a,&b),a||b) team.push_back(make_pair(b,a));
  sort(team.begin(),team.end());
  for(int i=team.size()-1,a=0,b=0; i>=0; i--){
    if(team[i].first != b){
      b = team[i].first;
      a++;
    }
    rank[team[i].second] = a;
  }
  int n;
  while(cin >>n) cout <<rank[n]<<endl;
  return 0;
}