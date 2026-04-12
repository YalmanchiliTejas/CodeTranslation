#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  long long n;
  cin >> n;
  long long a[n],ans[n];
  pair<ll, ll> p[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    p[i]=make_pair(a[i],i);
  }
  sort(p,p+n);
  for(int i=0;i<n;i++){
    if(i<n/2){
      ans[p[i].second]=p[n/2].first;
    }else{
      ans[p[i].second]=p[n/2-1].first;
    }
  }
  for(int i=0;i<n;i++){
    cout << ans[i] << endl;
  }
  return 0;
}
