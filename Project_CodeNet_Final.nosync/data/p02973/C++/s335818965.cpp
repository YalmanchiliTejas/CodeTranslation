#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  reverse(vec.begin(),vec.end());
  int INF = 1e9+10;
  vector<int> dp(N,INF);
  vector<int>::iterator pos;
  int idx;
  for(int i=0; i<N; i++){
    pos = upper_bound(dp.begin(),dp.end(),vec.at(i));
    idx = distance(dp.begin(),pos);
    dp.at(idx) = vec.at(i);
  }
  
  int ans = 0;
  for(int i=0; i<N; i++){
    //cout << dp.at(i) << " ";
    if(dp.at(i) != INF){
      ans = i;
    }
  }
  cout << ans+1 << endl;    
}