//答え見ました
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  deque<int>d;
  for(int i=0; i<n; i++){
    int p = lower_bound(d.begin(),d.end(),a[i])-d.begin();
    if(p==0){
     d.push_front(a[i]); 
    }
    else d[p-1] = a[i];
  }
  int ans = d.size();
  cout << ans << endl;
  
}
  
