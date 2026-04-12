#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL
#define PI 3.141592653589793
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vll B(0);
  ll bsize = 0;
  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    if(i == 0){
      B.push_back(A);
      bsize++;
    }
    else if(B.at(0) < A){
      B.at(0) = A;
    }
    else if(B.at(bsize-1) >= A){
      B.push_back(A);
      bsize++;
    }
    else{
      int ok = bsize-1;
      int ng = 0;
      while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(B.at(mid) < A) ok = mid;
        else ng = mid;
      }
      B.at(ok) = A;
    }
  }
  cout << B.size() << endl;
}