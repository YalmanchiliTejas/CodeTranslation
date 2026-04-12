#include <bits/stdc++.h>
using namespace std;

int main() {

  int  n;  cin >> n;
  vector<int>  h(n);
  for(int i=0;i<n;++i) cin >> h[i];

  int tmp=0;
  int ans=1;
  for(int i=n-1;i>0;--i){
    tmp=1;
    for(int j=i-1;j>=0;--j){
      if(h[i]>=h[j]) tmp=1;
      else {
	tmp=0;
	break;
      }
    }if(tmp==1) ans++;
  }

  cout << ans << endl;    

}
