#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int INF = 10000000;

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
using Graph = vector<vector<int>>;
/*
*/
ll s[100],p[100];
ll func(ll N, ll X){//レベルNバーガーの下からX層に含まれるパティの枚数
      if(N == 0){
          if(X <=0) return 0;
          else return 1;
      }
      else if(X == 1) return 0;
      else if(1 < X && X <= 1 + s[N-1])  return func(N-1,X-1);
      else if(X == 2 + s[N-1]) return p[N-1] + 1;
      else if(2 + s[N-1] < X && X <= 2 + 2*s[N-1]) return p[N-1] + 1 + func(N-1,X-2-s[N-1]);
      else if(X == 3 + 2*s[N-1]) return 2*p[N-1] + 1;
}

int main() {
   ll N,X;
   cin >> N >> X;
   //vector<ll> s(N);//レベルiバーガーの層数
   //vector<ll> p(N);//レベルiバーガーのパティの枚数
   s[0] = 1;
   p[0] = 1;
   for(int i = 1;i<=N;i++){
       s[i] = s[i-1]*2 + 3;
       p[i] = p[i-1]*2 + 1;
   }
  cout << func(N,X) << endl;
}