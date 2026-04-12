#include<bits/stdc++.h>
using namespace std;
int main(){
  int mh=0;
  int n,ans=1;
  cin >> n >> mh;
  for(int i=1;i<n;i++){
    int h;
    cin >> h;
    if(h >= mh) ans++;
    mh = max(h,mh);
  }
  cout << ans << endl;
  
}
