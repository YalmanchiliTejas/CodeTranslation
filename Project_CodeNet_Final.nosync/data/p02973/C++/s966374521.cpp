#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define ALL(x) (x).begin(),(x).end()
using namespace std;
using ll=long long;

int main(){
  int N; cin>>N;
  int A[N]; REP(i,N) cin>>A[i];
  vector<ll> v={-1};
  REP(i,N) {
    auto itr=lower_bound(ALL(v),A[i]);
    if(itr==v.begin()) v.insert(v.begin(),A[i]);
    else *--itr=A[i];
  }
  cout<<v.size()<<endl;
}