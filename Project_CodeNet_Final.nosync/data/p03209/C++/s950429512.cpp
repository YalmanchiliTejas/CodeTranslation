#include<bits/stdc++.h>
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
const int MOD = 1000000007;

bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
ll a[51];
ll p[51];
ll solve(ll N,ll X){
  if(X == 0)
    return 0;
  if(a[N] == X){
    return p[N];
  }else{
    if(X >= (a[N]+1)/2 ){
      return 1+p[N-1]+solve(N-1,X-a[N-1]-2);
    }else{
      return solve(N-1,X-1);
    }
  }
}

int main()
{
  ll N,X;
  a[0] = 1;
  p[0] = 1;
  REP(i,50){
    a[i+1] = 2*a[i]+3;
    p[i+1] = p[i]*2+1;
  }
  cin >> N >> X;
  cout << solve(N,X) << endl;
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
