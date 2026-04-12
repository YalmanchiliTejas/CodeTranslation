#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0){
      break;
    }
    vector<int> a(n);
    int ma=0;
    int mi=1000;
    int sum=0;
    rep(i,n){
      cin >> a[i];
      ma=max(a[i],ma);
      mi=min(a[i],mi);
      sum+=a[i];
    }
    sum=sum-mi-ma;
    int ave=sum/(n-2);
    cout << ave << endl;
  }
  return 0;
  
}

