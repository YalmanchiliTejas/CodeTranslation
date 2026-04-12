#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)
 
int main(){
  string s;
  cin>>s;
  if(s[0]==s[1] && s[1]==s[2]){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
}