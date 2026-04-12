#include <iostream>
#include <string>
using namespace std;

int main(){
  int dice[6]={1,2,4,3,5,6};
  string s;
  int n,temp,ans;

  while(cin >> n){
    ans=1;
    dice[0]=1;dice[1]=2;dice[2]=4;dice[3]=3;dice[4]=5;dice[5]=6;
    for(int i=0;i<n;i++){
      cin >> s;
      if(s=="North"){
	temp=dice[0];
	dice[0]=dice[1];
	dice[1]=dice[5];
	dice[5]=dice[4];
	dice[4]=temp;
	ans+=dice[0];
      }else if(s=="East"){
	temp=dice[0];
	dice[0]=dice[2];
	dice[2]=dice[5];
	dice[5]=dice[3];
	dice[3]=temp;
	ans+=dice[0];
      }else if(s=="West"){
	temp=dice[0];
	dice[0]=dice[3];
	dice[3]=dice[5];
	dice[5]=dice[2];
	dice[2]=temp;
	ans+=dice[0];
      }else if(s=="South"){
	temp=dice[0];
	dice[0]=dice[4];
	dice[4]=dice[5];
	dice[5]=dice[1];
	dice[1]=temp;
	ans+=dice[0];
      }else if(s=="Right"){
	temp=dice[1];
	dice[1]=dice[3];
	dice[3]=dice[4];
	dice[4]=dice[2];
	dice[2]=temp;
	ans+=dice[0];
      }else if(s=="Left"){
	temp=dice[1];
	dice[1]=dice[2];
	dice[2]=dice[4];
	dice[4]=dice[3];
	dice[3]=temp;
	ans+=dice[0];
      }
    }
    if(n!=0){
    cout << ans << endl;
    }
  }

}