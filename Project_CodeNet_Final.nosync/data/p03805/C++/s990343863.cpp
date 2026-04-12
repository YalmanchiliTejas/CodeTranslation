#include<bits/stdc++.h>
using namespace std;

int N,M,ans=0;
bool check(vector<vector<int>> &data,int x,int y){
  for(int i=0;i<data.at(x).size();i++){
    if(data.at(x).at(i)==y)return true;
  }
  return false;
}

int main(){
  cin>>N>>M;
  vector<vector<int>> data(N+1);
  for(int i=0;i<M;i++){
    int a,b;cin>>a>>b;
    data.at(a).push_back(b);data.at(b).push_back(a);
  }
  vector<int> nd(N-1);
  for(int i=0;i<N-1;i++)nd.at(i)=i+2;
  sort(nd.begin(),nd.end());
  do{
    int p=0;
    if(!check(data,1,nd.at(p)))continue;
    if(nd.size()==1)goto trip;
    while(p+1){
      if(!check(data,nd.at(p),nd.at(p+1))){p=-1;break;}
      p++;
      if(p>N-3)break;
    }
    if(p==-1)continue;
    trip:
    ans++;
  }while(next_permutation(nd.begin(),nd.end()));
  
  cout<<ans<<endl;
  return 0;
}