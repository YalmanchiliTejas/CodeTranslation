#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
long long counta=0;
long long countb=0;
for(long long i=0;i<s.size();i++){
  if(s[i]=='A'){
    counta++;
  }
  else{
    countb++;
  }
}
if(counta>0&&countb>0){
  cout<<"Yes"<<endl;
}
else{
  cout<<"No"<<endl;
}

  return 0;
}