#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  int N; cin >> N;
  v<int> A(N);
  rep(i,N) cin >> A[i];
  sort(ALL(A));
  deque<int> d;
  d.push_back(A[0]);
  int right=1,left=N-1;
  while(right<=left){
    if(right==left){
      d.push_front(A[right]);
      break;
    }
    if(right+1==left){
      d.push_front(A[right]);
      d.push_back(A[left]);
      break;
    }
    if(right+1==left-1){
      d.push_front(A[left-1]);
      d.push_back(A[left]);
      d.push_front(A[right]);
      break;
    }
    d.push_front(A[left-1]);
    d.push_back(A[left]);
    d.push_front(A[right]);
    d.push_back(A[right+1]);
    right+=2;
    left-=2;
  }
  int ans=0;
  rep(i,N-1){
    ans+=abs(d[i]-d[i+1]);
  }
  d.clear();
  d.push_back(A[N-1]);
  right=0,left=N-2;
  while(right<=left){
    if(right==left){
      d.push_front(A[right]);
      break;
    }
    if(right+1==left){
      d.push_front(A[right]);
      d.push_back(A[left]);
      break;
    }
    if(right+1==left-1){
      d.push_front(A[right]);
      d.push_back(A[right+1]);
      d.push_front(A[left]);
      break;
    }
    d.push_front(A[right]);
    d.push_back(A[right+1]);
    d.push_front(A[left-1]);
    d.push_back(A[left]);
    right+=2;
    left-=2;
  }
  int tans=0;
  rep(i,N-1){
    tans+=abs(d[i]-d[i+1]);
  }

  cout << max(ans,tans) << endl;
  return 0;
}
