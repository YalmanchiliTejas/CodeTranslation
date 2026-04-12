#include <bits/stdc++.h>
using namespace std;
int n,res[200007];
pair<int,int> a[200007];
int main(){
  cin >> n;
  for(int i = 1; i<=n; i++) cin >> a[i].first, a[i].second = i;
  sort(a+1,a+n+1);
  int k = 1;
  for(int i = 1; i<=n; i++){
    if(i==(n/2+1)) {
      res[a[i].second] = a[n/2].first;
      // printf("res for %dth is %d\n", a[i].second, a[n/2].first);

    }
    else if(i<(n/2+1)){
      res[a[i].second] = a[n/2+1].first;
      // printf("res for %dth is %d\n", a[i].second, a[n/2+1].first);
    }
    else{
      res[a[i].second] = a[n/2].first;
      // printf("res for %dth is %d\n", a[i].second, a[n/2].first);
    }

  }
  for(int i = 1; i<=n; i++) std::cout << res[i] << '\n';
}
