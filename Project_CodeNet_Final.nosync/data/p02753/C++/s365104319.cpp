#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  char s[3];cin>>s[0];
  string res="No";
  for(int i=1;i<3;i++){
    cin>>s[i];
    if(s[i]!=s[i-1]){
      res ="Yes";
      break;
    }
  }
  cout<<res<<endl;
}