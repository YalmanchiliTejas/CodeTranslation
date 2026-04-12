#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
  int N,T,E; cin >> N >> T >> E ;
  vector<int> x(N);
  cinf(N,x);
  for(int i=0;i<N;i++){
    int cnt=0;
    while(cnt <= T+E){
      cnt += x[i];
      if(cnt >= T-E && cnt <= T+E){
        cout << i+1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}

