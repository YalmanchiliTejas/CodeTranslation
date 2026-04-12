#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,n) for(long long int i=0;i<(long long int)(n);i++)

int main(){
  string s;
  cin>>s;
  int a=0;
  if(s.at(0)!=s.at(1)){
    a++;
  }
  if(s.at(2)!=s.at(1)){
    a++;
  }
  if(a==0){
    cout<<"No"<<endl;
  }
  
  if(a!=0){
    cout<<"Yes"<<endl;
  }
}
  