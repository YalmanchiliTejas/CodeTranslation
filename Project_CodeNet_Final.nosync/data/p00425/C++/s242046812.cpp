#include<bits/stdc++.h>
using namespace std;

int sum=1;
int main(){
  int n;
  string operate;
  while(cin>>n,n!=0){
    sum=1;
    int dice[6]={1,6,2,5,3,4};
    int changedice[6]={0};
    for(int i=0;i<n;i++){
      cin>>operate;
      if(operate[0]=='N'){
	changedice[3]=dice[0];
	changedice[2]=dice[1];
	dice[0]=dice[2];
	dice[1]=dice[3];
	dice[2]=changedice[2];
	dice[3]=changedice[3];
	sum+=dice[0];
      }else if(operate[0]=='W'){
	changedice[5]=dice[0];
	changedice[4]=dice[1];
	dice[0]=dice[4];
	dice[1]=dice[5];
	dice[4]=changedice[4];
	dice[5]=changedice[5];
	sum+=dice[0]; 
      }else if(operate[0]=='E'){
	changedice[4]=dice[0];
	changedice[5]=dice[1];
	dice[0]=dice[5];
	dice[1]=dice[4];
	dice[4]=changedice[4];
	dice[5]=changedice[5];
	sum+=dice[0];
      }else if(operate[0]=='S'){
	changedice[2]=dice[0];
	changedice[3]=dice[1];
	dice[0]=dice[3];
	dice[1]=dice[2];
	dice[2]=changedice[2];
	dice[3]=changedice[3];
	sum+=dice[0];
      }else if(operate[0]=='L'){//1,6,2,5,3,4->1,6,4,3,2,5
	changedice[2]=dice[5];
	changedice[3]=dice[4];
	dice[4]=dice[2];
	dice[5]=dice[3];
	dice[2]=changedice[2];
	dice[3]=changedice[3];
	sum+=dice[0];
      }else if(operate[0]=='R'){
	changedice[2]=dice[4];
	changedice[3]=dice[5];
	dice[4]=dice[3];
	dice[5]=dice[2];
	dice[2]=changedice[2];
	dice[3]=changedice[3];
	sum+=dice[0];
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}