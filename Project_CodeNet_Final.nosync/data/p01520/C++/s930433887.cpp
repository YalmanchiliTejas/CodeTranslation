#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int xs[1000001];
int main(){

  int N,T,E;
  cin>>N>>T>>E;
  for(int i=0;i<N;i++)cin>>xs[i];
  for(int i=0;i<N;i++){
    for(int j=1;j<10000;j++){
      int a=xs[i]*j;
      if(abs(T-a)<=E){
	cout<<i+1<<endl;
	return 0;
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}