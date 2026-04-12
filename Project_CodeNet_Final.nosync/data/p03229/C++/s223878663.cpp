#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 100000000000;
typedef pair<int,int> P;
typedef long long ll;
struct Sho {
    int X; 
    int Y; 
    Sho(int x, int y) : X(x), Y(y) { }
};
using Graph = vector<vector<Sho>>;

/*
*/

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N){
    cin >> A[i];
  }

  sort(A.begin(),A.end());
  
 
  ll ans1 = 0;
  ll ans2 = 0;
  if(N%2== 1){
    for(int i = 0;i<N/2 + 1;i++){
      if(i == N/2 || i == N/2 - 1) ans1 -= A[i];
      else ans1 -= A[i]*2;
    }
    for(int i = N/2 + 1;i<N;i++){
      ans1 += A[i]*2;
    }

    reverse(A.begin(),A.end());//降順
    for(int i = 0;i<N/2 + 1;i++){
      if(i == N/2 || i == N/2 - 1) ans2 += A[i];
      else ans2 += A[i]*2;
    }
    for(int i = N/2 + 1;i<N;i++){
      ans2 -= A[i]*2;
    } 
    cout << max(ans1,ans2) << endl;
  }
  
  if(N%2 == 0){
    reverse(A.begin(),A.end());//降順
    ll ans = 0;
    for(int i = 0;i<N/2;i++){
      if(i == N/2-1) ans += A[i];
      else ans += A[i]*2;
    }
    for(int i = N/2;i<N;i++){
      if(i == N/2) ans -= A[i];//引く項のうち最大のやつを1回引く
      else ans -= A[i]*2;
    } 

    cout << ans << endl;
  }
}