#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin>>N;
  vector<ll> v(N);
  for(int i = 0; i < N; i++) {
    int x;
    cin>>x;
    v[i]=-x;
  }
  vector<ll> ans;
  for(int i = 0; i < N;i++) {
    auto ite=upper_bound(ans.begin(),ans.end(),v[i]);
    if(ite==ans.end()) ans.push_back(v[i]);
    else *ite=v[i];
  }
  cout<<ans.size()<<endl;
}