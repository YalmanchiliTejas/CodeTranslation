# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

uintmax_t combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int modPow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v,int N,bool visited[nmax]){
  bool all_visited = true;

  for(int i = 0; i < N; i++){
    if(visited[i] == false) all_visited = false;
  }

  if(all_visited){
  return 1;
  }

  int ret = 0;

  rep(i,N){
  if(graph[v][i] == false) continue;
  if(visited[i]) continue;

  visited[i] = true;
  ret+=dfs(i,N,visited);
  visited[i] = false;
  }

  return ret;
}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  bool visited[nmax];
  rep(i,n){
    visited[i] = false;
  }

  visited[0] = true;
  cout << dfs(0,n,visited) << endl;

    
  return 0;
}