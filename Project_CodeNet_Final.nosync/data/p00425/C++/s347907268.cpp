#include<iostream>
using namespace std;

#define TOP 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define NORTH 4
#define BOTTOM 5
#define DIRECTIONS 6

int main()
{
  int n,i,t,top;
  string s;
  int die[DIRECTIONS];
  while(cin>>n,n){
    for(i=0;i<DIRECTIONS;i++)die[i]=i+1;

    top=1;
    for(i=0;i<n;i++){
      cin>>s;
      if(s=="North"){
	t=die[TOP];
	die[TOP]=die[SOUTH];
	die[SOUTH]=die[BOTTOM];
	die[BOTTOM]=die[NORTH];
	die[NORTH]=t;
      }
      if(s=="West"){
	t=die[TOP];
	die[TOP]=die[EAST];
	die[EAST]=die[BOTTOM];
	die[BOTTOM]=die[WEST];
	die[WEST]=t;
      }
      if(s=="East"){
	t=die[TOP];
	die[TOP]=die[WEST];
	die[WEST]=die[BOTTOM];
	die[BOTTOM]=die[EAST];
	die[EAST]=t;
      }
      if(s=="South"){
	t=die[TOP];
	die[TOP]=die[NORTH];
	die[NORTH]=die[BOTTOM];
	die[BOTTOM]=die[SOUTH];
	die[SOUTH]=t;
      }
      if(s=="Left"){
	t=die[NORTH];
	die[NORTH]=die[EAST];
	die[EAST]=die[SOUTH];
	die[SOUTH]=die[WEST];
	die[WEST]=t;
      }
      if(s=="Right"){
	t=die[NORTH];
	die[NORTH]=die[WEST];
	die[WEST]=die[SOUTH];
	die[SOUTH]=die[EAST];
	die[EAST]=t;
      }
      top+=die[TOP];
    }
    cout<<top<<endl;
  }
}