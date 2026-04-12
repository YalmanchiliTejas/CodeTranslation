#include<iostream>
using namespace std;
int main(){
  int n,ans,i,m,h;
  cin >> n;ans = m = 0;
  for(i=0;i<n;i++){
    cin >> h;
    if(h >= m){
      ans += 1;
      m = h;
    }
  }
  cout << ans << endl;
}
