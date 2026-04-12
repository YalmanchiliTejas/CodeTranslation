#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<long long> a(N);
  for(auto& x: a){
    cin >> x;
  }

  long long ans = 0;
  while(true){
    bool ok = true;
    for(int i = 0; i < N; i++){
      if(a[i] >= N){
        ok = false;
        long long cnt = a[i] / N;
        for(int j = 0; j < N; j++){
          if(j != i){
            a[j] += cnt;
          }
        }
        a[i] -= N * cnt;
        ans += cnt;
      }
    }
    if(ok){
      break;
    }
  }
  cout << ans << endl;
}

