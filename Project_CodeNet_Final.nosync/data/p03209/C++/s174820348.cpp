#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

// L[0] = P    size = 1
// L[2] = BLPLB = B P P P B  size = 
// L[3] = BLPLB = B BPPPB P BPPPB B = BBPPPBPBPPPBB
// L[4] = BBBPPPBPBPPPBBPBBPPPBPBPPPBBB

//Get number of P.
//P[i] = 2*P[i-1]+1  P[0] = 1
//
//Get numbe of length l
//l[i] = 2*l[i-1]+3,  l[0] = 1
//

ll rec(int n, ll x){
  if(n == 0) return 1;
  ll len = (1LL<<(n+1)) - 3;
  ll num = (1LL<<n) - 1;
  if(x == 1) return 0;
  else if(x <= len+1) return rec(n-1,x-1);
  else if(x == len+2) return num+1;
  else if(x <  len+2+len) return num+1+rec(n-1,x-(len+2));
  else return num+1+num;
}


int main(){
  ll n,x;
  cin >> n >> x;
  cout << rec(n,x) << endl;
}
