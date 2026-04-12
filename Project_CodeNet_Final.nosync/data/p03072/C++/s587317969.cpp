#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int h[N];
  for(int i=0; i<N; i++) cin >> h[i];
  int hh[N];
  hh[0]=h[0];
  for(int i=0; i<N-1; i++) hh[i+1] = max(hh[i], h[i+1]);
  int ans = 1;
  for(int i=1; i<N; i++) if(h[i]>=hh[i-1]) ans++;
  cout << ans << endl;
}