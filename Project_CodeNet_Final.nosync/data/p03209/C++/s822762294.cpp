#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long

int n,x;
vint B(51),P(51);

int rec(int nn,int xx){
  if(nn == 0){
    return 1;
  }
  else if(xx <= 1){
    return 0;
  }
  else if(xx <= 1 + B[nn-1]){
    return rec(nn-1,xx-1);
  }
  else if(xx == 2 + B[nn-1]){
    return P[nn-1] + 1;
  }
  else if(xx <= 2 + 2*B[nn-1]){
    return P[nn-1] + 1 + rec(nn-1,xx-2-B[nn-1]);
  }
  else{
    return 2*P[nn-1] + 1;
  }
}

signed main(){
  cin >> n >> x;
  B[0] = 1;
  P[0] = 1;
  rep1(i,n){
    B[i] = B[i-1]*2 + 3;
    P[i] = P[i-1]*2 + 1;
  }
  cout << rec(n,x) << endl;
  //rep(i,n) cout << B[i] << endl;
}