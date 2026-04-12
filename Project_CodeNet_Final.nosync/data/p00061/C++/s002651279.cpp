#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
  int a,b;
  vector<pair<int ,int> > log;
  map<int,int> old;
  while(scanf("%d,%d",&a,&b),a||b) log.push_back(make_pair(-b,a));
  sort(log.begin(), log.end());
  for(int i=0,j=0,k = 1; j<log.size(); j++){
    if(k!=log[j].first){
      k = log[j].first;
      i++;
    }
    old[log[j].second] = i;
  }
  int n;
  while(cin>>n) cout <<old[n]<<endl;
  return 0;
}