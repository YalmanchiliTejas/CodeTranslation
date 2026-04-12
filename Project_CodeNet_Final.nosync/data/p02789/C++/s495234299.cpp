#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M){
  if(N==M)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  solve(N, M);
  return 0;
}
