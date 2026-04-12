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

  int r,g,b;

  cin>>r>>g>>b;

  int ans=(r*100)+(g*10)+b;

  if(ans%4){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  
  return 0;

}


