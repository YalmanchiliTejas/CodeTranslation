#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf = numeric_limits<ll>::max()/3;

int main(void){
  int n;
  vector< P > v;
  vector< int > res;
  cin >> n;
  res.resize(n);
  for(int i = 0;i < n;++i){
    int tmp;
    cin >> tmp;
    v.push_back(P(tmp,i));
  }
  sort(v.begin(),v.end());
  for(int i = 0;i < n;++i){
    int j = v[i].second;
    if(i < n/2)
      res[j] = v[n/2].first;
    else
      res[j] = v[(n-1)/2].first;
  }
  for(int i = 0;i < n;++i)
    cout << res[i] << endl;
  return 0;
}
