#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(void){
  map<int,int> point2rank;
  map<int,int> team2point;
  vector<int> points;
  int p,s;
  while(1){
    scanf("%d,%d",&p,&s);
    if(p==0 && s==0)break;
    points.push_back(s);
    team2point[p]=s;
  }
  sort(points.begin(),points.end());
  points.erase(unique(points.begin(),points.end()),points.end());
  for(int i=0;i<points.size();i++){
    point2rank[points[i]]=points.size()-i;
  }
  int q;
  while(cin>>q){
    cout<<point2rank[team2point[q]]<<endl;
  }
  return 0;
}

