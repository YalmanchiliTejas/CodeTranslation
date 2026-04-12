#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,x=0;cin>>N>>M;
  vector<int>s(N);
  vector<pair<int,int>>p(M);
  for(int i=0;i<M;i++)cin>>p.at(i).first>>p.at(i).second;
  for(int i=0;i<N;i++)s.at(i)=i+1;
  do{
    int i;
    for(i=1;i<N;i++){
      int j;
      for(j=0;j<M;j++)if(min(s.at(i),s.at(i-1))==p.at(j).first&&max(s.at(i),s.at(i-1))==p.at(j).second)break;
      if(j==M)break;
    }
    if(i==N)x++;
  }while(next_permutation(s.begin()+1,s.end()));
  cout<<x<<endl;
}
