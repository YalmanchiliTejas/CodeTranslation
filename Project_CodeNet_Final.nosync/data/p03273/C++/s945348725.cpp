#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w;
  cin >> h >> w;
  vector<string> a(h);
  vector<bool> x(h),y(w);
  for(long i=0;i<h;i++) cin >> a[i];
  for(long i=0;i<h;i++) {
    for(long j=0;j<w;j++) {
      if(a[i][j]=='#') x[i]=true,y[j]=true;
    }
  }
  for(long i=0;i<h;i++) {
    if(x[i]) {
      for(long j=0;j<w;j++) {
        if(y[j]) cout << a[i][j];
      }
      cout << endl;
    }
  }
}