#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll N;cin>>N;
  vll A(N);rep(i,N)cin>>A[i];
  deque<int> d;
  for(int i=0;i<N;++i){
    int p = lower_bound(all(d),A[i]) - d.begin();
    if(p==0) d.push_front(A[i]);
    else d[p-1] = A[i];
  }
  cout<<d.size()<<endl;
}