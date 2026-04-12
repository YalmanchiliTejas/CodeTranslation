#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int d;
  long long a[200005];
  map<long long, int> ma;
  int ans = 0;

  a[0] = 0;
  for(int i = 1;i <= n;++i){
    cin >> d;
    a[i] = a[i - 1] + d;
    if(a[i] == 0){
      ans = max(ans, i);
    }else if(ma[a[i]] == 0){
      ma[a[i]] = i;
    }else{
      ans = max(ans, i - ma[a[i]]);
    }
  }

  cout << ans << endl;

  return 0;
}

