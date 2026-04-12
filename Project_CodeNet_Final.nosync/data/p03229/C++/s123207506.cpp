#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long a[100000];
  long long sum=0, sum2=0;
  int ptt;
  int i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n, greater<int>());
  //5 4 4
  //4 5 4 = 2
  //
  if(n==3){
    sum=a[0]+a[1]-a[2]*2;
    sum2=a[0]*2-a[1]-a[2];
    cout << max(sum, sum2) << '\n';
    return 0;
  }
  if(n==2){
    sum=a[0]-a[1];
    cout << sum << '\n';
    return 0;
  }

  if(n%2==1){
    ptt=n/2;
    for (i=0; i < ptt; i++) {
      sum+=(2*a[i]);
    }
    sum-=a[i];
    i++;
    sum-=a[i];
    i++;
    for(;i<n;i++){
      sum-=(2*a[i]);
    }
    ptt=n/2-1;
    for (i=0; i < ptt; i++) {
      sum2+=(2*a[i]);
    }
    sum2+=a[i];
    i++;
    sum2+=a[i];
    i++;
    for(;i<n;i++){
      sum2-=(2*a[i]);
    }
    if(sum<sum2){
      sum=sum2;
    }

  }else{
    ptt=n/2-1;
    for (i=0; i < ptt; i++) {
      sum+=(2*a[i]);
    }
    sum+=a[i];
    i++;
    sum-=a[i];
    i++;
    for(;i<n;i++){
      sum-=(2*a[i]);
    }
  }


  cout << sum << '\n';
  return 0;
}
