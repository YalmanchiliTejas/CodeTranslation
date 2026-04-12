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

  char c;

  cin>>c;

  if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }
  
  return 0;

}
