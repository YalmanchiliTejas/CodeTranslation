#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,cnt=0,ans=0;
  cin >> N;
  vector<int> high(N);
  for(int i=0;i<N;i++){
  cin >> high[i];
  }

  for(int i=1;i<N;i++){
     for(int j=0;j<i;j++){
       if(high[i] >= high[j]){
       cnt++;
       }
     }
     if(cnt ==i){
      ans++;

     }
   cnt =0;
  }

  cout << ans+1 << endl;
}
