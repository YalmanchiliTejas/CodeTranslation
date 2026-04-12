#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++) {
    cin>>H[i];
  }
  int ma=H[0];
  int ans=1;
  for(int i=1;i<N;i++) {
    if(ma<=H[i]) {
      ans++;
      ma=H[i];
    }
  }
    cout<<ans<<endl;
}