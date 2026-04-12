#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  
  int n = (x-z)/(y+z);
  
  cout << n << endl;
  
  return 0;
}