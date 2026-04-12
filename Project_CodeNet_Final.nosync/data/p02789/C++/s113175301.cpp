#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n, m;
string res = "No";

int main(){
  cin >> n >> m;
  if(m == n){
    res = "Yes";
  }
  
  cout << res << endl;
  return 0;
}
