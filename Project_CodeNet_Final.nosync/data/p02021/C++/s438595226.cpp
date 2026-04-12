#include <bits/stdc++.h>

using namespace std;

int main(){
  int i,j;
  int n; cin >> n;
  vector<int> a(n);
  for(i=0;i<n;++i) cin >> a[i];
  for(i=a[0];i>0;--i){
    int work=0;
    for(j=0;j<n;++j){
      work+=a[j];
      work-=i;
      if(work<0) break;
    }
    if(work>=0) break;
  }
  cout << i << endl;
  return 0;
} 

