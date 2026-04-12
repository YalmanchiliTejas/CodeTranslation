#include<iostream>

using namespace std;
int n;
int main(){
  while(1){
    int res=1,top=1,bot=6,north=5,east=3,south=2,west=4,temp=0;
    string str;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
      cin>>str;
      if(str=="North"){
	temp=top;
	top=south;
	south=bot;
	bot=north;
	north=temp;
	res+=top;
      }
      else if(str=="East"){
	temp=top;
	top=west;
	west=bot;
	bot=east;
	east=temp;
	res+=top;
      }
      else if(str=="West"){
	temp=top;
	top=east;
	east=bot;
	bot=west;
	west=temp;
	res+=top;
      }
      else if(str=="South"){
	temp=top;
	top=north;
	north=bot;
	bot=south;
	south=temp;
	res+=top;
      }
      else if(str=="Right"){
	temp=south;
	south=east;
	east=north;
	north=west;
	west=temp;
	res+=top;
      }
      else if(str=="Left"){
	temp=south;
	south=west;
	west=north;
	north=east;
	east=temp;
	res+=top;
      }
    }
    cout<<res<<endl;
  }
}