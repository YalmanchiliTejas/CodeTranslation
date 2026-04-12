#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, T, X;
vi a, p;
string S;
int f(int N, int X){
  if(N == 0 && X==1) return 1;
  if(X == 1) return 0;
  else if(1 < X && X <= 1+a[N-1]) return f(N-1,X-1);
  else if(X == 2+a[N-1]) return p[N-1]+1;
  else if(2+a[N-1] < X && X < a[N]) return p[N-1]+1+f(N-1,X-2-a[N-1]);
  else if(X == a[N]) return p[N];
}
signed main(){
  cin >> N >> X;

  a.push_back(1);
  p.push_back(1);
  rep2(i,1,N+1){
    a.push_back(a[i-1]*2+3);
    p.push_back(p[i-1]*2+1);
  }

  cout << f(N,X) << endl;
  return 0;
}
