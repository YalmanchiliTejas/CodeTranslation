#include<iostream>
#include<string>
using namespace std;
int main(){
  int k[4][3];
  int n;
  int count;
  int tmp;
  string hou;
  while(1){
    count=1;
    k[0][1]=1;
    k[1][0]=4;
    k[1][1]=2;
    k[1][2]=3;
    k[2][1]=6;
    k[3][1]=5;

    cin>>n;
    if(n==0) break;
    for(int i=0;i<n;i++){
      cin>>hou;
      if(hou=="North"){
	tmp=k[3][1];
	k[3][1]=k[0][1];
	k[0][1]=k[1][1];
	k[1][1]=k[2][1];
	k[2][1]=tmp;
      }
      else if(hou=="West"){
	tmp=k[1][0];
	k[1][0]=k[0][1];
	k[0][1]=k[1][2];
	k[1][2]=k[2][1];
	k[2][1]=tmp;
      }
      else if(hou=="East"){
	tmp=k[1][2];
	k[1][2]=k[0][1];
	k[0][1]=k[1][0];
	k[1][0]=k[2][1];
	k[2][1]=tmp;
      }
      else if(hou=="South"){
	tmp=k[1][1];
	k[1][1]=k[0][1];
	k[0][1]=k[3][1];
	k[3][1]=k[2][1];
	k[2][1]=tmp;
      }
      else if(hou=="Right"){
	tmp=k[1][1];
	k[1][1]=k[1][2];
	k[1][2]=k[3][1];
	k[3][1]=k[1][0];
	k[1][0]=tmp;
      }
      else if(hou=="Left"){
	tmp=k[1][1];
	k[1][1]=k[1][0];
	k[1][0]=k[3][1];
	k[3][1]=k[1][2];
	k[1][2]=tmp;
      }
      count+=k[0][1];
    }
    cout<<count<<endl;
  }
}