#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,a,b,i,j,s=0;
  cin>>N>>M;
  vector<pair<int,int>>E(M);
  for(i=0;i<M;i++){
    cin>>a>>b;
    E.at(i)=make_pair(a,b);
  }
  vector<int>v(N);
  for(i=0;i<N;i++)v.at(i)=i+1;
  sort(v.begin(),v.end());
  do{
    if(v.at(0)==1){
      for(i=1;i<N;i++){
        for(j=0;j<M;j++)if((v.at(i-1)==E.at(j).first&&v.at(i)==E.at(j).second)||(v.at(i)==E.at(j).first&&v.at(i-1)==E.at(j).second))break;
        if(j==M)break;
      }
      if(i==N)s++;
    }
  }while(next_permutation(v.begin(),v.end()));
  cout<<s<<endl;
}