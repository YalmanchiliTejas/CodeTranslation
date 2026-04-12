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

ll dfs(string S,int K){
  if(K==0){
    return 1;
  }
  if(S.size()==1){
    if(K==1){
      return S.at(0)-'0';
    }else{
      return 0;
    }
  }
  if(S.at(0)=='0'){
    return dfs(S.substr(1),K);
  }
  int N=S.size();
  ll ret1;
  ll ret2;
  if(K==3){
    ret1=(N-1)*(N-2)*(N-3)*729/6;
    ret2=(N-1)*(N-2)*81/2;
  }else if(K==2){
    ret1=(N-1)*(N-2)*81/2;
    ret2=(N-1)*9;
  }else{
    ret1=(N-1)*9;
    ret2=1;
  }

  return ret1+ret2*(S.at(0)-'0'-1)+dfs(S.substr(1),K-1);
}

int main()
{
  string S;
  cin >> S;
  int K;
  cin >> K;

  cout << dfs(S,K) << endl;
}