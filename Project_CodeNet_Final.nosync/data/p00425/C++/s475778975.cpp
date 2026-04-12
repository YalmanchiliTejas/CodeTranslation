#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){

  while(1){

  int n;

  int ans = 1;

  int s[7] = {0,1,2,3,4,5,6};

  scanf("%d",&n);

  if(n == 0) break;

  for(int i = 0;i < n;i++){
    char sai[10];
    cin >> sai;
    int t1=s[1],t2=s[2],t3=s[3],t4=s[4],t5=s[5],t6=s[6];
    if(!strcmp(sai, "North")){
      s[1]=t2;
      s[2]=t6;
      s[5]=t1;
      s[6]=t5;
    }else if(!strcmp(sai, "East")){
      s[1]=t4;
      s[3]=t1;
      s[4]=t6;
      s[6]=t3;
    }else if(!strcmp(sai, "West")){
      s[1]=t3;
      s[3]=t6;
      s[4]=t1;
      s[6]=t4;
    }else if(!strcmp(sai, "South")){
      s[1]=t5;
      s[2]=t1;
      s[5]=t6;
      s[6]=t2;
    }else if(!strcmp(sai, "Right")){
      s[2]=t3;
      s[3]=t5;
      s[4]=t2;
      s[5]=t4;
    }else{
      s[2]=t4;
      s[3]=t2;
      s[4]=t5;
      s[5]=t3;
    }
    ans += s[1];
  }

  cout << ans << endl;

  }

  return 0;


}
