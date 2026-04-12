#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
   int n,sum;
   string str;
   while(cin>>n,n){
     int dice[6]={1,6,2,5,3,4};
     sum=1;
     for(int i=1;i<=n;i++){
       cin>>str;
       if(str=="North") {swap(dice[0],dice[3]);swap(dice[0],dice[1]);swap(dice[0],dice[2]);sum=sum+dice[0];}
      else if(str=="East") {swap(dice[1],dice[5]);swap(dice[0],dice[1]);swap(dice[1],dice[4]);sum=sum+dice[0];}
       else if(str=="West")  {swap(dice[0],dice[5]);swap(dice[0],dice[4]);swap(dice[1],dice[4]);sum=sum+dice[0];}
       else if(str=="South") {swap(dice[0],dice[2]);swap(dice[0],dice[3]);swap(dice[1],dice[3]);sum=sum+dice[0];}
       else if(str=="Right") {swap(dice[2],dice[5]);swap(dice[2],dice[4]);swap(dice[3],dice[4]);sum=sum+dice[0];}
       else if(str=="Left")  {swap(dice[2],dice[5]);swap(dice[3],dice[5]);swap(dice[3],dice[4]);sum=sum+dice[0];}

     }
     cout<<sum<<endl;
   }
  return 0;
  }