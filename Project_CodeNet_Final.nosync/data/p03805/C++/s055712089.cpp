#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
int i, N, M, a, b, ans=0; cin >> N >> M; vector<int> ar(N-1);
map<pair<int, int>, bool> C;
REP(i, M){ cin >> a >> b; a--; b--; C[make_pair(a, b)]=true; C[make_pair(b, a)]=true; }
REP(i, N-1){ ar[i]=i; }
do {
  bool f=true;
  REP(i, N-1){ 
    if(i==0){ if(C[make_pair(0, ar[i]+1)]==false){ f=false; break; } }
    else{ if(C[make_pair(ar[i-1]+1, ar[i]+1)]==false){ f=false; break; } }
  }
  if(f){ ans++; }
} while(next_permutation(ar.begin(), ar.end()));
cout << ans << "\n";
}