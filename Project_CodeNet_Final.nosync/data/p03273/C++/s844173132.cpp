#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
ll bpow(ll,ll,ll);
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B);
mat pow(mat A,ll n);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};


bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  int N,H,W,cnt=0;
  bool gyo[101],retu[101];
  REP(i,101){
    gyo[i] = true;
    retu[i] = true;
  }
  char masu[101][101];
  cin >> H >> W;
  REP(i,H)cin >> masu[i];
  REP(i,H){
    cnt = 0;
    REP(j,W){
      if(masu[i][j] == '.')
        cnt++;
    }
    if(cnt == W){
      gyo[i] = false;
    }
  }
  REP(i,W){
    cnt = 0;
    REP(j,H){
      if(masu[j][i] == '.')
        cnt++;
    }
    if(cnt == H){
      retu[i] = false;
    }
  }
  REP(i,H){REP(j,W){
    if(gyo[i] && retu[j]){
      cout << masu[i][j];
    }else
      continue;
    }
    if(gyo[i])
      cout << endl;
  }
  
  return 0;
}

int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return ;
  if(ranks[x] < ranks[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(ranks[x] == ranks[y]) ranks[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

ll bpow(ll a, ll n,ll mod){
  int i = 0;
  ll res=1;
  while(n){
    if(n & 1)
      res = (res*a) % mod;
    a = (a*a) % mod;
    n >>= 1;
  }
  return res;
}
const int MOD = 1000000007;
mat mul(mat &A, mat &B){
  mat C(A.size(),vec(B[0].size()));
    REP(i,A.size())REP(k,B.size())REP(j,B[0].size()){
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  }
  return C;
}

mat pow(mat A,ll n)
{
  mat B(A.size(),vec(A.size()));
  REP(i,A.size()){
    B[i][i] = 1;
  }
  while(n > 0){
    if ( n & 1) B = mul(B,A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}
