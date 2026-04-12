#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<vector>
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;

bool cmp(const P &p,const P &q){
  if(p.S != q.S)return p.S > q.S;
  return p.F < q.F;
}

int main(){
  int id,sol;
 vector<P> info;
  while(true){   
    scanf("%d,%d",&id,&sol);
    if(id+sol == 0)break;
    info.push_back(P(id,sol));
  }
  sort(info.begin(),info.end(),cmp);
  int pre = info[0].S;
  int cnt = 1;
  map<int,int> rank;
  for(int i=0;i<=info.size();i++){
    if(pre != info[i].S){cnt++; pre = info[i].S;}
    rank[info[i].F] = cnt;
  }
  int exec;
  while(cin >> exec){
    cout << rank[exec] << endl;
  }
  return 0;
}