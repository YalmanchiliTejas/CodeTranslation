/*  
    |\_/|
    |* *|
    \_+_/
*/
#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  string str;

  cin>>str;

  for(int i=0;i<str.length()-1;i++){
    if(str[i]=='A'&&str[i+1]=='C'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;
  
  return 0;
  
}


