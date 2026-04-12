#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;


int main(void){
 int H,W;
 int check=1;
 char s[150][150];
 bool flag[150][150];

 cin>>H>>W;
 for(int i=0; i<H; i++)
  for(int j=0; j<W; j++)flag[i][j]=true;

 for(int i=0; i<H; i++)cin>>s[i];
 
 for(int i=0; i<H; i++){
  for(int j=0; j<W; j++){
   if(s[i][j]=='.');
   else check=0;
  }
  if(check==1)for(int j=0; j<W; j++)flag[i][j]=false;
  check=1;
 }
 
 for(int i=0; i<W; i++){
  for(int j=0; j<H; j++){
   if(s[j][i]=='.');
   else check=0;
  }
  if(check==1)for(int j=0; j<H; j++)flag[j][i]=false;
  check=1;
 }

 for(int i=0; i<H; i++){
  check=0;
  for(int j=0; j<W; j++){
   if(flag[i][j]==true){
    std::cout<<s[i][j];
	check=1;
   }
  }
  if(check==1)std::cout<<std::endl;
 }
 
 return 0;
}