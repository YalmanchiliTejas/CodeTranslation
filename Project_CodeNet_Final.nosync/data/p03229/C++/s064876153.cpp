#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long>a(n);
  int i,j;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  long ans = 0;
  long tmp = 0;
  if(n%2==0){
    for(i=0;i<n/2-1;i++){
      ans -= 2*a[i];
    }
    ans -= a[n/2-1];
    ans += a[n/2];
    for(i=n/2+1;i<n;i++){
      ans += 2*a[i];
    }
  }else{
    for(i=0;i<n/2-1;i++){
      ans -= 2*a[i];
    }
    ans -= a[n/2-1];
    ans -= a[n/2];
    for(i=n/2+1;i<n;i++){
      ans += 2*a[i];
    }

    for(i=0;i<n/2;i++){
      tmp -= a[i]*2;
    }
    tmp += a[n/2] + a[n/2+1];
    for(i=n/2+2;i<n;i++){
      tmp += 2*a[i];
    }
    if(tmp>ans)ans = tmp;
  }


  cout << ans << endl;
}
