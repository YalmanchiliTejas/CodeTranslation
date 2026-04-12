#include<bits/stdc++.h>
using namespace std;

int foo(char ch){
  if(ch == 'y' ||ch == 'u' || ch == 'i' ||ch == 'o' ||ch == 'p' ||
     ch == 'h' || ch == 'j' ||ch == 'k' || ch == 'l' ||
     ch == 'n'|| ch == 'm') return 1;
  else return 0;
}

int main(){
  int temp, temp2;
  int i, j, k;
  string str;
  while(1){
    int count = 0;
    cin>>str;
    if(str == "#") break;
    for(i = 0; i < (int)str.size(); i++){
      
      if(i){
	temp2 = temp;
	temp = foo(str[i]);
	if(temp != temp2) count++;
	
      }else {
	temp = foo(str[0]);
	temp2 = foo(str[0]);
      }

      
    }


    cout<<count<<endl;
    
  }
  return 0;
}

