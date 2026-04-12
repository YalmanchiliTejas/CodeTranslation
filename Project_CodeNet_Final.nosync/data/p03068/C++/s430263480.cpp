#include<iostream>
using namespace std ;

int main()
{
  int N ;
  cin>>N ;
  char S[N] ;
  for(int i=0;i<N;i++) cin>>S[i] ;
  int K ;
  cin>>K ;
  
  for(int i=0;i<N;i++){
    if(S[i]!=S[K-1]) S[i]='*' ;
    cout<<S[i] ;
  }
  
  
  return 0 ;
}