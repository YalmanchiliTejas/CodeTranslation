#include<iostream>

using namespace std;

int main(){
  int n;
 
  while(cin >> n&&n!=0){
    int dice[6]={1,2,3,5,4,6};

    int plus;
    int ans=1;
    for(int i=0;i<n;i++){
      string inp;
      
      cin >> inp;

      if(inp=="North"){
	plus=dice[1];
	dice[1]=dice[5];dice[5]=dice[3];dice[3]=dice[0];dice[0]=plus;
	ans+=plus;
      }else if(inp=="East"){
	plus=dice[4];
	dice[4]=dice[5];dice[5]=dice[2];dice[2]=dice[0];dice[0]=plus;
	ans+=plus;
      }else if(inp=="West"){
	plus=dice[2];
	dice[2]=dice[5];dice[5]=dice[4];dice[4]=dice[0];dice[0]=plus;
	ans+=plus;
      }else if(inp=="South"){
	plus=dice[3];
	dice[3]=dice[5];dice[5]=dice[1];dice[1]=dice[0];dice[0]=plus;
	ans+=plus;
      }else if(inp=="Right"){
	plus=dice[1];
	dice[1]=dice[2];dice[2]=dice[3];dice[3]=dice[4];dice[4]=plus;
	ans+=dice[0];
      }else if(inp=="Left"){
	plus=dice[1];
	dice[1]=dice[4];dice[4]=dice[3];dice[3]=dice[2];dice[2]=plus;
	ans+=dice[0];
      }else{
	cout << "error!" << endl;
	break;
      }

    }
    cout << ans << endl;
  }
}