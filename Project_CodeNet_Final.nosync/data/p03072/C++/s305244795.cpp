#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define int long long

using namespace std;

signed main(){
  int N;
  cin >> N;
  int H[N];
  rep(i, N) cin>>H[i]; 
  int max = 0; 
  int res = 0;
  rep(i, N){
    if(max<=H[i]){
      max = H[i];
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
