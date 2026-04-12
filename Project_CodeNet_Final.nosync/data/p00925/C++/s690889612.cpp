#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  string str;
  cin>>str;
  int n;
  cin>>n;
  int ansl=(int)str[0]-48;
  for(int i=1;i<=int(str.size())/2;i++){
    if(str[2*i-1]=='+'){
      ansl+=(int(str[2*i])-48);
    }else{
      ansl*=(int(str[2*i])-48);
    }
  }
  int ansm=0;
  vector<int> vec;
  for(int i=0;i<int(str.size());i+=2){
    if((i+1>=(int)str.size()) || (str[i+1]=='+')){
      vec.push_back((int)str[i]-48);
    }else{
      int c=((int)str[i]-48);
      for(int j=i+2;j<(int)str.size();j+=2){
	c*=((int)str[j]-48);
	if((j+1>=(int)str.size()) || (str[j+1]=='+')){
	  vec.push_back(c);
	  i=j;
	  break;
	}
      }
    }
  }
  for(int i=0;i<(int)vec.size();i++)
    ansm+=vec[i];
  //  cout<<" l->"<<ansl<<" m->"<<ansm<<endl;
  if(ansm==ansl){
    if(ansm==n){
      cout<<"U"<<endl;
    }else{
      cout<<"I"<<endl;
    }
  }else{
    if(ansm==n){
      cout<<"M"<<endl;
    }else if(ansl==n){
      cout<<"L"<<endl;
    }else{
      cout<<"I"<<endl;
    }
  }
  return 0;
}