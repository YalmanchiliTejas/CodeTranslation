#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(int N){
  vector<int> S(N);
  for(int i=0;i<N;i++) cin>>S[i];

  sort(S.begin(),S.end());

  int ans=0;
  for(int i=1;i<N-1;i++) ans+=S[i];
  cout<<ans/(N-2)<<endl;
}

int main(){
  int n;
  while(1){
    cin>>n;
    if(n==0) break;
    solve(n);
  }

  return 0;
}

