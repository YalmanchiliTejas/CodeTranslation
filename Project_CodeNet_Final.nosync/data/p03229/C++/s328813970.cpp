#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];
  sort(A, A+N);
  reverse(A,A+N);

  ll ans = 0;
  int m = N/2;
  rep(i,N){
    if (i<m-1) ans += 2*A[i];
    else if (i==m-1) ans += A[i];
    else if (i==m && N%2) ans += A[i];
    else if (i==m && N%2==0) ans -= A[i];
    else ans -= 2*A[i]; 
  }
  ll ans2 = 0;
  rep(i,N){
    if (i<m) ans2 += 2*A[i];
    else if (i<=m+1) ans2 -= A[i];
    else ans2 -= 2*A[i];
  }
  if (N%2) chmax(ans, ans2);
  cout << ans << endl;


  
  // cout << fixed << setprecision(10);
  
  return 0;
}
