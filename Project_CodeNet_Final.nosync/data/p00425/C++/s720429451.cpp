#include<iostream>
#include<string>
using namespace std;
int dice[6] ;

void Dice(string a,int dice[]){
  int dicetmp[6];
    for(int i = 0;i<6;i++){
      dicetmp[i] = dice[i];
    }
   if(a == "Right"){
    dice[0] = dicetmp[0];
    dice[1] = dicetmp[2];
    dice[2]  = dicetmp[3];
    dice[3]  = dicetmp[4];
    dice[4] = dicetmp[1];
    dice[5] = dicetmp[5];
  } else 
     if(a == "Left"){
    dice[0] = dicetmp[0];
    dice[1] = dicetmp[4];
    dice[2]  = dicetmp[1];
    dice[3]  = dicetmp[2];
    dice[4] = dicetmp[3];
    dice[5] = dicetmp[5];
  } else 

  if(a == "North"){
    dice[0] = dicetmp[3];
    dice[1] = dicetmp[0];
    dice[2]  = dicetmp[2];
    dice[3]  = dicetmp[5];
    dice[4] = dicetmp[4];
    dice[5] = dicetmp[1];
  } else 
    if(a == "West"){
    dice[0] = dicetmp[4];
    dice[1] = dicetmp[1];
    dice[2]  = dicetmp[0];
    dice[3]  = dicetmp[3];
    dice[4] = dicetmp[5];
    dice[5] = dicetmp[2];
  } else 
if(a == "South"){
    dice[0] = dicetmp[1];
    dice[1] = dicetmp[5];
    dice[2]  = dicetmp[2];
    dice[3]  = dicetmp[0];
    dice[4] = dicetmp[4];
    dice[5] = dicetmp[3];
  } else
if(a == "East"){
    dice[0] = dicetmp[2];
    dice[1] = dicetmp[1];
    dice[2]  = dicetmp[5];
    dice[3]  = dicetmp[3];
    dice[4] = dicetmp[0];
    dice[5] = dicetmp[4];
  }

}
  
  int main(){
    
    int n,s; string dist;
    while(cin >> n){
      if(n == 0)
	return 0;
      dice[0]=1;dice[1]=5;dice[2]=4;dice[3]=2;dice[4]=3;dice[5]=6; 
      
      s = 1;
      for(int i = 0;i<n;i++){
	cin >> dist;
	 Dice(dist,dice);
	s = s + dice[0];
      }
      cout << s <<endl;
    }
  }
     