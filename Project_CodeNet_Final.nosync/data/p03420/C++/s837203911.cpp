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

ll lcm(ll a, ll b){
  return a/gcd(a,b) * b;
}
ll func2(ll n){
  ll res = 0;
  while(n%2 == 0){
    n /= 2;
    res++;
  }
  return res;
}

ll zyou(ll a,ll b){//a＾b
  ll res = 1;
  for(int i = 1;i<=b;i++){
    res *= a;
  }
  return res;
}
using Graph = vector<vector<char>>;

ll calc(ll a, ll b, ll p){//aのb乗をpで割った余り
  if(b == 0) return 1;

  else if(b%2 == 0){
    ll d = calc(a,b/2,p);
    return (d*d)%p;
  }
  else if(b%2 == 1){
    return (a * calc(a,b-1,p))%p;
  }
}

typedef pair<int,int> P;

bool is_prime(int n){//nが素数であるかどうか判定 iで割り切れると素数でない
    if(n == 1) return false;//1は例外
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}
int factorial(int a){
  int res = 1;
  while(a){
    res *= a;
    a--;
  }
  return res;
}

int main(){
  ll N,K;
  cin >> N >> K;
  ll ans = 0;
  if(K == 0){
    ans = N*N;
    cout << ans << endl;
    return 0;
  }
  for(int b = 1;b <= N;b++){
    if(K > b-1) ans = 0;
    else{
      ans += b-K;
      ans += (N-b+1)/b * (b-K);
      if((N-b+1)%b - 1 >= K) ans += (N-b+1)%b - 1 -K +1;
    }
  }
  cout << ans << endl;
}