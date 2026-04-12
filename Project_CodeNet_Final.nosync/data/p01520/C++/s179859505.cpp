#include<iostream>
using namespace std;
int main(){
  int N,T,E,A;
  cin>>N>>T>>E;
  for(int i=0;i<N;i++){
    cin>>A;
    if(T%A<=E||A-T%A<=E){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}