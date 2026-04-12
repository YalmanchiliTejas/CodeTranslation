#include <iostream>
using namespace std;
int main(){
  int n,i,t,sum,data[7];
  string in;
  while(1){
    cin >> n;
    if(n==0) break;
    sum=0;
    for(i=0;i<=6;i++) data[i]=i;
    for(i=0;i<n;i++){
      cin >> in;
      if(in=="North"){
	t=data[1];
	data[1]=data[2];
	data[2]=data[6];
	data[6]=data[5];
	data[5]=t;
      }
      else if(in=="East"){
	t=data[1];
	data[1]=data[4];
	data[4]=data[6];
	data[6]=data[3];
	data[3]=t;
      }
      else if(in=="West"){
	t=data[1];
	data[1]=data[3];
	data[3]=data[6];
	data[6]=data[4];
	data[4]=t;
      }
      else if(in=="South"){
	t=data[1];
	data[1]=data[5];
	data[5]=data[6];
	data[6]=data[2];
	data[2]=t;
      }
      else if(in=="Right"){
	t=data[2];
	data[2]=data[3];
	data[3]=data[5];
	data[5]=data[4];
	data[4]=t;
      }
      else{
	t=data[2];
	data[2]=data[4];
	data[4]=data[5];
	data[5]=data[3];
	data[3]=t;
      }
      sum+=data[1];
    }
    cout << sum+1 << endl;
  }
  return 0;
}