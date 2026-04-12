#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int haba = X-Z;
  int hitori = Y+Z;
  int ans = 0;
  for(int i=0;;i++){
    if(haba<hitori) break;
    haba -= hitori;
    ans++;
  }
  
  cout << ans << endl;
}