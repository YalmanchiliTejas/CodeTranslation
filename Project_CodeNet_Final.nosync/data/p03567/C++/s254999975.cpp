#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s;
  int a=-1,c=-1,count=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      a=i;
      if(s[a+1]=='C'){
        cout<<"Yes";
        count++;
        break;
      }
    }
  }
  if(count==0){
    cout<<"No"<<endl;
  }
  cout<<endl;
}