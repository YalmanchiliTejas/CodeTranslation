#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
const ll P =  1000000007;
ll factorial(ll n){
   ll ans = 1;
   for(int i = n;i>=1;i--){
     ans *= i;
     ans %= P;
   }
   return ans;
}
using Graph = vector<vector<int>>;

ll kzyou(ll a,ll k){//aのk乗を返す
    ll zyou = 1;
    for(ll i = 1;i<=k;i++){
        zyou *= a;
    }
    return zyou;
}

int main(){
  int N,M;
  cin >> N >> M;
  if(N == M) cout << "Yes" << endl;
  else cout << "No" << endl;

 }