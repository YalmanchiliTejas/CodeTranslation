#include<iostream>
using namespace std;
int main(){
	int N,H[100];
  int count=1,high=0;
  cin>>N;
  
  for (int i=0;i<N;i++){
  	cin>>H[i];
    if(i==0){
    	high=H[0];
    }else{
    	if(high<=H[i]){
        	count++;
          high=H[i];
        }
    }
  }
  cout <<count;
  return 0;
}