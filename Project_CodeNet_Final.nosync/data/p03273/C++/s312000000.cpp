#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
  	if(n==k){
      return 1;
    }
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int H,W;
    cin>>H>>W;
    vector<bool>A(H);
    vector<bool>B(W);
    vector<vector<char>> C(H, vector<char>(W));
  	rep(i,H){
      A[i]=false;
    }
  rep(i,W){
    B[i]=false;
  }
    rep(i,H){
        rep(j,W){
            cin>>C[i][j];
            if(C[i][j]=='#'){
                A[i]=true;
                B[j]=true;
            }
        }
    }
    rep(i,H){
      	int cnt=0;
        rep(j,W){
            if(A[i]==true&&B[j]==true){
                cout<<C[i][j];
              	cnt++;
            }
        }
      	if(cnt!=0){
        cout<<""<<endl;
        }
    }
}
