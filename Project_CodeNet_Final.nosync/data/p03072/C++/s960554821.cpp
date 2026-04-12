#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int n,a[20],ans=0,max=0;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(max<a[i]) {
      max=a[i];
    }
    if(max<=a[i]) {
      ans++;
    }
    else {
      ans+=0;
    }
  }
cout << ans << endl;
  
}

