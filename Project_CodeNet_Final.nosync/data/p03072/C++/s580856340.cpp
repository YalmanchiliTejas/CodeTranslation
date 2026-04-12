#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++) cin>>H[i];
  int ans=1;
  for(int i=1;i<N;i++){
    for(int j=i-1;j>=0;j--){
      if(H[i]<H[j]) break;
      else if(j==0) ans++;
    }
  }
  cout<<ans<<endl;
}
