#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long ans;
  cin>>n;
  long long a[n],b[n];
  for(int i=0;i<n;i++){
    long long l;
    cin>>l;
    a[i]=l;
    b[i]=l;
  }
  sort(b,b+n);
  for(int i=0;i<n;i++){
    if(a[i]<b[n/2])ans=b[n/2];
    else ans=b[(n/2)-1];
    cout<<ans<<endl;
  }
}
