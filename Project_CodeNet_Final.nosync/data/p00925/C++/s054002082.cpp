#include<bits/stdc++.h>
using namespace std;

string str;

int cal1(){

  int ans=0;
  
  for(int i=1 ; i <= str.size() ; i+=2){
    if(str[i]=='+' || i == str.size()){
      ans+=atoi(&str[i-1]);
    }else if(str[i]=='*'){
      int temp=atoi(&str[i-1]);
      while(str[i] == '*'){
	temp*=atoi(&str[i+1]);
	i+=2;
      }
      ans+=temp;
    }
  }
  
  return ans;
}
int cal2(){
  
  int ans=atoi(&str[0]);
  
  for(int i=1 ; i < str.size() ; i+=2){
    int x=atoi(&str[i+1]);
    if(str[i]=='+'){
      ans+=x;
    }else if(str[i]=='*'){
      ans*=x;
    }
  }
  
  return ans;
  
}
int main(){
  
  int x;
  
  cin >>str;
  cin >>x;
  
  int ans1=cal1();
  int ans2=cal2();
  
  if(x==ans1 && x==ans2){
    cout <<"U"<<endl;
  }else if(x==ans1){
    cout <<"M"<<endl;
  }else if(x==ans2){
    cout <<"L"<<endl;
  }else{
    cout <<"I"<<endl;
  }
  
  return 0;
}