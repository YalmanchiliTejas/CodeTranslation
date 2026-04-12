#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, X, M;
  cin >> N >> X >> M;
  map<long, long> mp;
  vector<long> data;
  long baf = X;
  mp[X];
  data.push_back(X);
  for(long i = 0; i < N - 1; i++){
    baf = (baf * baf) % M;
    if(mp.count(baf) != 0 || baf == 0)break;
    mp[baf];
  	data.push_back(baf);
  }
  long ans = 0;
  long flag = 0, size;
  if(baf == 0){
    for(long i = 0; i < data.size(); i++)ans += data.at(i);
  } else {
    for(long i = 0; i < data.size(); i++){
      if(baf == data.at(i)){
        flag = 1;
        size = data.size() - i;
      }
      if(flag == 0)ans += data.at(i);
      else ans += data.at(i) * ((N - i + size - 1) / size);
    }
  }
  cout << ans << endl;
  return 0;
}