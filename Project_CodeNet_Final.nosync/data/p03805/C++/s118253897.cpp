#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<bool>> road(N+1,vector<bool>(N+1,false));
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    road.at(a).at(b)=true;
    road.at(b).at(a)=true;
  }
  
  vector<int> town(0);
  for(int i=2;i<=N;i++){
    town.push_back(i);
  }

  int count=0;
  do{
    bool judge=true;
    if(road.at(1).at(town.at(0))==false){
      judge=false;
    }
    for(int i=0;i<N-2;i++){
      if (road.at(town.at(i)).at(town.at(i+1))==false){
        judge=false;
      }
    }
    if(judge){count++;}
  }while(next_permutation(town.begin(),town.end()));
  
  cout<<count<<endl;
}

