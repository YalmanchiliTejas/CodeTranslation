#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, max=0, count=0;
  cin >> N;
  vector<int> H(N);
  REP(i,N) cin >> H[i];
  REP(i,N) {
    if(H[i]>=max) {
      max=H[i]; 
      count++;
    }
  }
  cout << count << endl;
}