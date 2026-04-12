#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int kaijo(int a){
  int i,ans=1;
  for(i=1;i<=a;i++){
  ans*=i;
  }
  return ans;
}

int mathC(int a,int b){

  int i,ans=1;
  if(b>a/2) b=a-b;
  for(i=1;i<=b;i++){
    ans*=(a-i+1);
    ans/=i;
  }
  
  return ans;
}

int max(int x[],int N){
  int i,max=x[0];
	for(i=1;i<N;i++){
      if(max<x[i]) max=x[i];
    }
  return max;
}

int min(int x[],int N){
  int i,min=x[0];
	for(i=1;i<N;i++){
      if(min>x[i]) min=x[i];
    }
  return min;
}

int main(void){
  
  int ans=0;
  char S[3];
  
  cin >> S;
  
  if(S[0]==S[1]) ans++;
  if(S[1]==S[2]) ans++;
  if(S[2]=='A'||S[2]=='B') ans++;
  
  if(ans!=3){
  cout << "Yes" << endl;
  }else{
  cout << "No" << endl;
  }
  
	return 0; 
}