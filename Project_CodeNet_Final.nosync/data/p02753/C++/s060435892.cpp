#include <iostream>
using namespace std;

int main(){
	char s[3];
  	cin>>s;
  	int flag[2]={0};
  	for(int i=0;i<3;i++){
    	if(s[i]=='A') flag[0]=1;
      	else if(s[i]=='B') flag[1]=1;
    }
  
  	if(flag[0]==1 && flag[1]==1){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
    }
}