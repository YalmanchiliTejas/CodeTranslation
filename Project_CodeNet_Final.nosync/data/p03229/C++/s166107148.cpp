#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  // 端っこ: 1 それ以外: 2
  // 偶数: + 奇数 -
  int N; cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  vector<ll> cof(N,2);

  cof[0] = 1;
  cof[N-1] = 1;

  for(int i = 0; i < N; i++){
    if(i%2 == 1){
      cof[i] *= -1;
    }
  }
  sort(cof.begin(), cof.end());
  sort(A.begin(), A.end());

  ll max_val = 0;
  ll ans = 0;
  for(int i = 0; i < N; i++){
    ans += cof[i] * A[i];
  }
  max_val = ans;

  vector<ll> cof2(N,2);

  cof2[0] = 1;
  cof2[N-1] = 1;

  for(int i = 0; i < N; i++){
    if(i%2 == 0){
      cof2[i] *= -1;
    }
  }
  sort(cof2.begin(), cof2.end());
  ans = 0;
  for(int i = 0; i < N; i++){
    ans += cof2[i] * A[i];
  }

  max_val = max(max_val, ans);

  cout << max_val << endl;

}
