#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int r, g, b;
      cin >> r >> g >> b;
      string ans="NO";
        if((10*g+b)%4 == 0) ans="YES";
      cout << ans << endl;
}