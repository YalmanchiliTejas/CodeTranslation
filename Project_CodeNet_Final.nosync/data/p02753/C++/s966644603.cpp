#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
string s;
cin>>s;
int n=0;
if(s=="AAA"){
  n=1;
}
else if(s=="BBB"){
  n=1;
}
if(n==1){
  cout<<"No"<<endl;
}else{
  cout<<"Yes"<<endl;
}
return 0;
}

