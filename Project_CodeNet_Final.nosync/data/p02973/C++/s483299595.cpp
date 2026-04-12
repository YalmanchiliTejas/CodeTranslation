#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
#include <random>
#include <queue>
#include <deque>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin>>N;
  vector<int>A(N);
  multiset<int>B;
  REP(i,N)cin>>A[i];
  B.insert(A[0]);
  FOR(i,1,N){
    auto it = B.lower_bound(A[i]);
    if(it==B.begin()){
      B.insert(A[i]);
    }else{
      B.erase(--it);
      B.insert(A[i]);
    }
  }
  cout<<B.size()<<endl;
}
