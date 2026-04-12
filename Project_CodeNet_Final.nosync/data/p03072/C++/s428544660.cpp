#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  int max = 0;
  int ans = 0;
  for(int i = 0;i<a;i++){
    int b;
    cin >> b;
    if(max <= b){
      max = b;
      ans++;
    }
  }
  cout << ans << endl;
}
