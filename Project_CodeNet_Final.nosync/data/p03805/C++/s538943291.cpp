#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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

vector<bool> flag(8, true);
vvi edge(8, vi(0));

int result(int m, int n, vector<bool> flag){
  if(n == 0) return 1;
  int num = 0;
  for(int i = 0; i < edge.at(m).size(); i++){
    int next = edge.at(m).at(i);
    if(flag.at(next)){
      vector<bool> flag2 = flag;
      flag2.at(next) = false;
      num += result(next, n-1, flag2);
    }
  }
  return num;
}

int main(){
  int N, M;
  cin >> N >> M;
  
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge.at(a).push_back(b);
    edge.at(b).push_back(a);
  }

  flag.at(0) = false;
  cout << result(0, N-1, flag) << endl;

}