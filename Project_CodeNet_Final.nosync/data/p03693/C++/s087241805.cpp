#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if((b*10+c)%4==0){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
