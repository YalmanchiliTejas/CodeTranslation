#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c;
  d = b * 10 + c ;
  if(d % 4 == 0){
    cout << "YES\n";
  }
  else cout << "NO\n";
}
  
 