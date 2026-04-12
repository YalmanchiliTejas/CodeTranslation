#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
  int up;
  int down;
  int mae;
  int usiro;
  int right;
  int left;
}SAIKORO;
main(){
  char meirei[7];
  SAIKORO saikoro;
  while(1){
    int n,sub,goukei=1;
    saikoro.up=1;
    saikoro.down=6;
    saikoro.mae=2;
    saikoro.usiro=5;
    saikoro.right=3;
    saikoro.left=4;
    cin >> n;
    if(n==0)break;
    for (int i=0;i<n;i++){
      cin >> meirei;
      if(strcmp(meirei,"North")==0){
	sub=saikoro.up;
	saikoro.up=saikoro.mae;
	saikoro.mae=saikoro.down;
	saikoro.down=saikoro.usiro;
	saikoro.usiro=sub;
      }
      else if(strcmp(meirei,"East")==0){
	sub=saikoro.up;
	saikoro.up=saikoro.left;
	saikoro.left=saikoro.down;
	saikoro.down=saikoro.right;
	saikoro.right=sub;
      }
      else if(strcmp(meirei,"West")==0){
	sub=saikoro.up;
	saikoro.up=saikoro.right;
	saikoro.right=saikoro.down;
	saikoro.down=saikoro.left;
	saikoro.left=sub;
      }
      else if(strcmp(meirei,"South")==0){
	sub=saikoro.up;
	saikoro.up=saikoro.usiro;
	saikoro.usiro=saikoro.down;
	saikoro.down=saikoro.mae;
	saikoro.mae=sub;
      }
      else if(strcmp(meirei,"Right")==0){
	sub=saikoro.mae;
	saikoro.mae=saikoro.right;
	saikoro.right=saikoro.usiro;
	saikoro.usiro=saikoro.left;
	saikoro.left=sub;
      }
      else if(strcmp(meirei,"Left")==0){
	sub=saikoro.mae;
	saikoro.mae=saikoro.left;
	saikoro.left=saikoro.usiro;
	saikoro.usiro=saikoro.right;
	saikoro.right=sub;
      }
      goukei=goukei+saikoro.up;
    }
    cout << goukei << endl;
  }
  return 0;
}