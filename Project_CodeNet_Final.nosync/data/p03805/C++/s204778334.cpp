#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a,b,i,ans = 0;cin >> n >> m;bool ok;
  vector<int> ar(n);vector<vector<int>> k(n);
  for(i=0;i<n;i++) ar[i] = i;
  while(cin >> a >> b){
    a--;b--;
    k[a].push_back(b);
    k[b].push_back(a);
  }
  for(i=0;i<n;i++) sort(k[i].begin(),k[i].end());
  do{
    ok = true;
    for(i=1;i<n;i++){
      if(!binary_search(k[ar[i]].begin(),k[ar[i]].end(),ar[i-1])) ok = false;
    }
    ans += ok;
  } while(next_permutation(ar.begin()+1,ar.end()));
  cout << ans << endl;
}