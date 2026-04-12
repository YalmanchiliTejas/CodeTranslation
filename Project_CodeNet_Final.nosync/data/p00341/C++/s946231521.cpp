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

  
  int a[12];

  int cnt[100]={ };
  
  for(int i=0;i<12;i++){
    cin>>a[i];

    cnt[a[i]]++;
    
  }

  bool judge=0;
  
  for(int i=0;i<12;i++){

    if(cnt[a[i]]%4!=0){
      judge=1;
    }

  }  

  if(judge){
    cout<<"no"<<endl;
  }else {
    cout<<"yes"<<endl;
  }
  
  return 0;

}

