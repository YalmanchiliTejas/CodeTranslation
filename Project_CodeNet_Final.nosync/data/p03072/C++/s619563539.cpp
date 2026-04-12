#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,H;
  cin >> N;
  int ans=0;
  int maxx=0;
  for (int i=0;i<N;i++){
    cin >> H;
    ans=H>=maxx?ans+1:ans;
    maxx=max(H,maxx);
  }
  cout << ans <<endl;
}