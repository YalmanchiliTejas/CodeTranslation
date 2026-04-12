#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <array>

using namespace std;
using ll = long long;

bool check1(string s){
  if(s=="0")return true;
  else if(s[0]=='0'&& s.size()!=1)return false;
  else if(s.size()>3) return false;
  else {
    if(stoi(s)<=255)return true;
    else return false;
  }
}

int main(){
  string s;
  cin>>s;
  int len=s.size();
  int ans=0;
  for(int i=1;i<len;++i){
    for(int j=i+1;j<len;++j){
      for(int k=j+1;k<len;++k){
        string s1=s.substr(0,i),s2=s.substr(i,j-i), s3=s.substr(j,k-j), s4=s.substr(k,len-k);
        if(check1(s1) &&check1(s2) &&check1(s3) &&check1(s4) )ans++;
        //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<endl;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}

