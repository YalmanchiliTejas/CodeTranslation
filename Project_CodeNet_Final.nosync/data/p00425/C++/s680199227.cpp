#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
  int n;
  int ans;
  char cmd[100];
  int dice[3];
  
  cin>>n;
  while(n!=0){
    dice[0]=2;
    dice[1]=1;
    dice[2]=3;
  
    ans=1;
    int temp;
    for(int i=0;i<n;i++){
      cin>>cmd;
      if(strcmp(cmd,"North")==0){
	temp=dice[0];
	dice[0]=7-dice[1];
	dice[1]=temp;
      }else if(strcmp(cmd,"East")==0){
	temp=dice[1];
	dice[1]=7-dice[2];
	dice[2]=temp;
      }else if(strcmp(cmd,"West")==0){
	temp=dice[1];
	dice[1]=dice[2];
	dice[2]=7-temp;
      }else if(strcmp(cmd,"South")==0){
	temp=dice[0];
	dice[0]=dice[1];
	dice[1]=7-temp;
      }else if(strcmp(cmd,"Right")==0){
	temp=dice[0];
	dice[0]=dice[2];
	dice[2]=7-temp;
      }else if(strcmp(cmd,"Left")==0){
	temp=dice[0];
	dice[0]=7-dice[2];
	dice[2]=temp;
      }
      ans+=dice[1];
    }
    cout<<ans<<endl;
    cin>>n;
  }

  return 0;

}