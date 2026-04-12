#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){
  long long a,b,x; cin >> a >> b >> x;
  long long tmp=max(0LL,(x-b)/(a-b))%MOD;
  b%=MOD; x%=MOD;
  cout << (x+tmp*b)%MOD << endl;
  
  return 0;
}
