#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,k,i;
  string s;
  cin >> n >> s >> k;
  for(i=0;i<n;i++){
    if(s.at(i)!=s.at(k-1)){
      s.at(i)='*';
    }
  }
  
  cout << s << endl;
}