#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
  int a;
  cin >> a;
  int ans = 0;

  vector<int> b(a);
  rep(i,a){
    cin >> b[i];
  }
  rep(i,a){
    bool flag = true;
    for(int j=0;j<i;j++)
     {
       if(b[j]>b[i]){

       flag = false;
         break;
       }
     }
     if(flag) ++ans;
  }
  cout << ans << endl;
 return 0;
}