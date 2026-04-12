#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  long long int k, a, b; cin >> k >> a >> b;
  if(a <= b) {
    if(k <= a) {
      cout << 1 << endl;
      return 0;
    }
    cout << -1 << endl;
    return 0;
  }
  long long int num = 1;
  k -= a;
  num += ((k + (a-b) - 1) / (a-b)) * 2;
  cout << num << endl;

  return 0;
}


// EOF
