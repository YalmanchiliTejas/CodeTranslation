#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  	cin>>n;
  string s;
  	cin>>s;
  int k;
  	cin>>k;
  char c=s.at(k-1);
  for(int i=0;i<n;i++){
    if(s.at(i)!=c){
      s.at(i)='*';
    }
    else{
      continue;
    }
  }
    cout<<s<<endl;
    
}
