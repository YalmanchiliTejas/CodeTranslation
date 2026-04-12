#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;
 
int main()
{
  int N;
  int H[101];
  int res=1;
  cin >> N;
 
  rep(i,N) cin >> H[i];
 
  for(int i=1; i<N; i++) {
    bool oceanview=true;
    for(int j=0; j<i; j++){
      if(H[i]<H[j]) oceanview=false;
    }
    if(oceanview) res++;
  }
 
  cout << res << endl;
}