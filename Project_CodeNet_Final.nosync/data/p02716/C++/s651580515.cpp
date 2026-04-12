#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i = 0LL; i < N; i++) cin>>A[i];
  if(N%2==0){
    vector<ll> v(N);
    v[0]=A[0];
    v[1]=A[1];
    for(ll i = 2LL; i < N; i++){
      if(i%2==0) v[i]=v[i-2]+A[i];
      else v[i]=max(v[i-2],v[i-3])+A[i];
    }
    cout<<max(v[N-1],v[N-2])<<endl;
  }
  else {
    vector<vector<ll>> v(N,vector<ll>(2));
    v[0][0]=0;
    v[0][1]=A[0];
    v[1][0]=A[1];
    v[1][1]=A[1];
    v[2][0]=A[2];
    v[2][1]=A[0]+A[2];
    for(ll i = 3LL;i< N; i++){
      if(i%2==0) {
        v[i][0]=max(v[i-2][0],v[i-3][0])+A[i];
        v[i][1]=v[i-2][1]+A[i];
      }
      else {
        v[i][0]=max(v[i-2][0],v[i-3][1])+A[i];
        v[i][1]=v[i][0];
      }
    }
    cout<<max(v[N-1][0],max(v[N-2][0],v[N-3][1]))<<endl;
  }
}