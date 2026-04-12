#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main()
{
  int N ;
  cin>>N ;
  vector<pair<int,int>>X(N) ;
  for(int i=0;i<N;i++){
    cin>>X.at(i).first ;
    X.at(i).second=i  ;
  }
  sort(X.begin(),X.end()) ;
  //for(int i=0;i<N;i++) cout<<"("<<X.at(i).first<<","<<X.at(i).second<<")"<<endl ;
  vector<int>C(N) ;
  for(int i=0;i<N;i++){
    if(i<N/2) C.at(X.at(i).second)=X.at(N/2).first ;
    else C.at(X.at(i).second)=X.at(N/2-1).first ;
  }
  for(int i=0;i<N;i++) cout<<C.at(i)<<endl ;
  
  return 0 ;
}