#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
int main(){
  while(true){
    vector<int>shop(5);
    rep(i,5){
      int a,b;
      cin >> a >> b;
      if(a == 0 && b == 0){
        return 0;
      }
      shop[i] = a + b;
    }
    int Max = 0;
    rep(i,5)Max = max(shop[i],Max);
    rep(i,5){
      if(Max == shop[i]){
        cout << (char)('A' + i) << " " << shop[i] << endl;
        break;
      }
    }
  }
  return 0;
}
