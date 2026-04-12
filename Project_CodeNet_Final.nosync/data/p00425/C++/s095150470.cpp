#include <iostream>
#include <string>
using namespace std;
int main(){
  int i;
  while(cin>>i){
    if(i == 0) break;
    else{
  string w;
  int  dice[3]={1,2,3},jey[3]={1,2,3},ans=1;
  for(int j=0;j<i;j++){
    jey[0]=dice[0];
    jey[1]=dice[1];
    jey[2]=dice[2];
    cin>>w;
      if(w=="North"){
	dice[0]=jey[1];
	dice[1]=7-jey[0];
      } 
      if(w=="East"){
      dice[0]=7-jey[2];
      dice[2]=jey[0];
}
 if(w=="West"){
   dice[0]=jey[2];
   dice[2]=7-jey[0];
}
 if(w=="South"){
   dice[0]=7-jey[1];
   dice[1]=jey[0];
}
 if(w=="Right"){
   dice[1]=jey[2];
   dice[2]=7-jey[1];
}
 if(w=="Left"){
   dice[1]=7-jey[2];
   dice[2]=jey[1];
}
 ans+=dice[0];
  }
  cout<<ans<<endl;
    }}
  return 0;
}