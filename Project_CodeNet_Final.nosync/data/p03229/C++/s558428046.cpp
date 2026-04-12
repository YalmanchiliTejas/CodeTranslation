#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vll A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);    
  }
  sort(ALL(A));
  deque<ll> deq;
  for(int i = 0; i < N; i++){
    ll num;
    if(i % 2 == 0) num = A.at(i/2);
    else num = A.at(N-1 - i/2);

    if(deq.size() == 0){
      deq.push_front(num);
      continue;
    }

    if(i == N-1){
      if(abs(num - deq.front()) > abs(num - deq.back())) deq.push_front(num);
      else deq.push_back(num);
    }
    else{
      if(i % 4 == 0 || i % 4 == 3) deq.push_front(num);
      else deq.push_back(num);
    }
    
  }
  ll before = deq.front(); deq.pop_front();
  ll ans = 0;
  while(!deq.empty()){
    ll num = deq.front(); deq.pop_front();
    ans += abs(num - before);
    before = num;
  }
  cout << ans << endl;
}
