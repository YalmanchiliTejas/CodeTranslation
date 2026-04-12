#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()
#define YES()         printf("YES\n")
#define NO()          printf("NO\n")
#define Yes()         printf("Yes\n")
#define No()          printf("No\n")
#define in(a,x,b)     ((a) <= (x) && (x) < (b))

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;
using V = vector<int>;
using Vll = vector<ll>;
using Vstr = vector<string>;

template<class T> bool inline chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool inline chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T = int> T inline input() { T x; cin >> x; return (x); }
template<class T> void inline print(T& x) { cout << x << '\n'; }
#define debug(x) cerr << #x << ": " << x << endl;

const int dxs[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dys[] = { 0, -1, 0, 1, 1, -1, -1, 1 };
const int perm[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

bool isOK(V v, int index, int key) {
  if (v[index] >= key) return true;
  else return false;
}

int binary_search(V v, int key) {
  int left = -1;
  int right = (int)v.size();

  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (isOK(v, mid, key)) right = mid;
    else left = mid;
  }

  return right;
}

/*
int prime[1001001];
bool is_prime[1001001];

int sieve(int n) {
  int p = 0;
  for (int i = 0; i < n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < n; i++){
    if (is_prime[i]){
      prime[p++] = i;
      for (int j = 2*i; j < n; j+=i) is_prime[j] = false;
    }
  }
  return p;
}
*/

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(16);

  ll N;
  int X,M;
  cin >> N >> X >> M;

  V nextA(M);
  REP(i,M) {
    nextA[i] = (ll)i * i % M;
  }

  V trace(M, 0);
  trace[X] = 1;
  ll ans = X;
  int prev = ans;
  int ai;
  Vll traceans(M+1, 0);
  traceans[1] = ans;

  EACH(i,2,N) {
    ai = nextA[prev];
    if (trace[ai] == 0) {
      trace[ai] = i;
    } else {
      int loop_start = trace[ai];
      int loop_end = i;
      int loop_length = loop_end - loop_start;
      ll loop_sum = (traceans[loop_end-1] - traceans[loop_start-1]);
      ll loop_count = (N - i + 1) / loop_length;
      ll loop_amari = N - (loop_end + loop_length * loop_count);
      ans += ai;
      ans += loop_count * loop_sum;
      ans += traceans[loop_start + loop_amari] - traceans[loop_start];
      debug(ans);
      break;
    }
    ans += ai;
    traceans[i] = ans;
    prev = ai;
  }

  print(ans);
}

