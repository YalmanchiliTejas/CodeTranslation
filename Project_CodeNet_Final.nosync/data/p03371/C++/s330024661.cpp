#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

ll gcm(ll a,ll b);

int main(){
  int A,B,C,X,Y;
  int ans = 0;
  cin >> A >> B >> C >> X >> Y;
  if(A + B > 2*C){
    int Ccount = min(X,Y);
    ans += min(X,Y)*2*C;
    X -= Ccount;
    Y -= Ccount;
  }
  if(A<2*C){
    ans += A*X;
  }
  else{
    ans += 2*C*X;
  }
  if(B<2*C){
    ans += B*Y;
  }
  else{
    ans += 2*C*Y;
  }
  cout << ans << endl;
}





