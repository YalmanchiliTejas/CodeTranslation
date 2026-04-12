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

  int n;

  cin>>n;

  cout<<(800*n)-(200*(n/15))<<endl;
      
  return 0;

}


