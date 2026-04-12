#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
    A[i]*=-1;
  }
  
  vector<int> vec;
  vec.push_back(A[0]);
  FOR(i,1,N){
    auto iter=upper_bound(ALL(vec),A[i]);
    if(iter==vec.end()){
      vec.push_back(A[i]);
    }else{
      *iter=A[i];
    }
  }

  cout << vec.size() << endl;
}