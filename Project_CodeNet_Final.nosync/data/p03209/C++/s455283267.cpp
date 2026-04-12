#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int INF = 998244353;

using Graph = vector<vector<int>>;
/*
*/
ll s[100];//s[i]はレベルiバーガーの層数
ll p[100];//p[i]はレベルiバーガーのPの枚数

ll f(ll N,ll X){//レベルNバーガーの下からX層までに含まれるPの数
    if(N == 0) return 1;
    else if(X <= 1) return 0;
    else if(1 <= X && X <= s[N-1] + 1) return f(N-1,X-1);
    else if(X == s[N-1] + 2) return p[N-1] + 1;
    else if(s[N-1] + 2 < X && 2*s[N-1] + 2) return p[N-1] + 1 + f(N-1,X-2-s[N-1]);
    else if(X == 2*s[N-1] + 3) return 2*p[N-1] + 3;
}

int main() {
   ll N,X;
   cin >> N >> X;
   s[0] = 1;
   for(int i = 1;i<=N;i++){
       s[i] = s[i-1]*2 + 3; 
   }
   p[0] = 1;
   for(int i = 1;i<=N;i++){
       p[i] = p[i-1]*2 + 1; 
   }
   cout << f(N,X) << endl;
}