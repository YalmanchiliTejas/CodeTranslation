#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>

using namespace std;
int main(void){
 int N,K;
 string S;

 cin>>N>>S>>K;
 
 for(int i=0; i<S.length();i++){
  if(S[K-1]==S[i])cout<<S[K-1]; 
  else cout<<"*";
  
 }
 cout<<endl;
 return 0;
}