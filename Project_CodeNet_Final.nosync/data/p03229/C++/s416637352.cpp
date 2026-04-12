#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long> a(n);
  
  int i;
  for(i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  long ans1=0,ans2=0;
  if(n%2==0){
    for(i=0; i<n/2; i++){
      ans1=ans1+2*a[n-1-i]-2*a[i];
    }
    ans1=ans1-a[n/2]+a[n/2-1];
    cout << ans1; return 0;



  }else{
    for(i=n/2+1; i<n; i++){
      ans1=ans1+2*a[i];
    }
    for(i=0; i<n/2-1; i++){
      ans1=ans1-2*a[i];
    }
    ans1=ans1-a[n/2]-a[n/2-1];

    for(i=n/2+2; i<n; i++){
      ans2=ans2+2*a[i];
    }
    for(i=0; i<n/2; i++){
      ans2=ans2-2*a[i];
    }
    ans2=ans2+a[n/2]+a[n/2+1];
    cout << max(ans1,ans2); return 0;
  }
}