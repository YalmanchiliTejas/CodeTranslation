#include<bits/stdc++.h>
using namespace std;

#define lli long long int

/*** vector ***/

#define v vector<int>;
#define vp vector<int,int>;

/*** map ***/

#define mi map<int>;
#define md map<double>;
#define mc map<char>;
#define ms map<string>;

int dice[6]={1,5,3,2,4,6};

void changeN(void){
  swap(dice[0],dice[3]);
  swap(dice[3],dice[5]);
  swap(dice[5],dice[1]);
}

void changeE(void){
  swap(dice[0],dice[4]);
  swap(dice[4],dice[5]);
  swap(dice[5],dice[2]);
}

void changeS(void){
  swap(dice[0],dice[1]);
  swap(dice[1],dice[5]);
  swap(dice[5],dice[3]);
}

void changeW(void){
  swap(dice[0],dice[2]);
  swap(dice[2],dice[5]);
  swap(dice[5],dice[4]);
}

void changeR(void){
  swap(dice[1],dice[4]);
  swap(dice[4],dice[3]);
  swap(dice[3],dice[2]);
}

void changeL(void){
  swap(dice[1],dice[2]);
  swap(dice[2],dice[3]);
  swap(dice[3],dice[4]);
}

int main(){

  int n,sum=1;
  string com;

  while(cin >> n,n){
    for(int i=0;i<n;i++){
      cin >> com;
      if(com[0]=='N'){
	changeN();
	sum+=dice[0];
      }
      if(com[0]=='E'){
	changeE();
	sum+=dice[0];
      }
      if(com[0]=='W'){
	changeW();
	sum+=dice[0];
      }
      if(com[0]=='S'){
	changeS();
	sum+=dice[0];
      }
      if(com[0]=='L'){
	changeL();
	sum+=dice[0];
      }
      if(com[0]=='R'){
	changeR();
	sum+=dice[0];
      }      
    }
    cout << sum << endl;
    sum=1;
    dice[0]=1; dice[1]=5; dice[2]=3; dice[3]=2; dice[4]=4; dice[5]=6; 
  }
  
  return 0;
}