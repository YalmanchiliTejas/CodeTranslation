#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,ans=0,cur=0,res=0;
  cin >> n;
  
  for(i=0; i<n; i++){
    cin >> cur;
    if(cur>=res){
      res=cur;
      ans++;
    }
  }
  
  cout << ans;
}
  