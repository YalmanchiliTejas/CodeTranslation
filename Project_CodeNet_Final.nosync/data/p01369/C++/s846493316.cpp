#include<bits/stdc++.h>
using namespace std;
int main(){
  
  string left="qwertasdfgzxcvb",right="yuiophjklnm";
  string in;

  while(1){
    cin >>in;
    if(in == "#")break;
    int cnt=0;
    int hand=-1;//left 1 right 2
    
    for(int i=0 ; i < (int)in.size() ; i++){
      
      char key=in[i];
      
      if(left.find(key) != -1 && hand != 1){
	cnt++;
	hand=1;
      }else if(right.find(key) != -1 && hand !=2){
	cnt++;
	hand=2;
      }
    }
    
    cout <<cnt-1<<endl;
  }
  
  

  return 0;
}