#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int n;
  cin >> n;

  vector<string> A(n);
  REP(i, n) cin >> A[i];
  int B[26]={0};

  FOR(i,'a','z'+1){
    int MIN = INF;
    REP(j,n){
      int cnt = 0;
      REP(k,A.at(j).size()){
        if(A.at(j).at(k)==i){
          cnt++;
        }
      }
      MIN = min(MIN,cnt);
    }
    B[i-'a']=MIN;
  }

  FOR(i,'a','z'+1){
    REP(j,B[i-'a']){
      char x = i;
      cout << x;
    }
  }
  cout << endl;
}