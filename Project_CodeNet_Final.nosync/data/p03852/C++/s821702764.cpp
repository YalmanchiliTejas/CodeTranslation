#include <bits/stdc++.h>
using namespace std;
 
int main(){
 char c;
  cin>>c;
  for(int i=0;i<5;i++){
  	if("aeiou"s.at(i)==c){
    	cout<<"vowel"<<endl;
      break;
    }
    if(i==4){
      cout<<"consonant"<<endl;
    }   
  }

}