#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  sort(all(A));
  vector<ll> B = A; reverse(all(B));
  ll ans = 0;
  // 1 2 3 6 8
  // 2 6 1 8 3
  //
  // 1 1 3 4 5 9
  // 4 1 9 1 5 3
  //
  // 1 5 5
  // 5 1 5
  ll ans1=0, ans2=0;
  vector<ll> C;
  C.pb(A[N/2]);
  int cnt = 0;
  while(cnt!=N-1){
    if(cnt%2==1) C.pb(A[N-1-cnt/2]);
    else C.pb(A[cnt/2]);
    cnt++;
  }
  rep(i,N){
    // cout << C[i] << endl;
    if(i==0) continue;
    ans1 += abs(C[i]-C[i-1]);
  }
  vector<ll> D;
  D.pb(A[N/2]);
  cnt = 0;
  while(cnt!=N-1){
    if(cnt%2==0) D.pb(A[N-1-cnt/2]);
    else D.pb(A[cnt/2]);
    cnt++;
  }
  rep(i,N){
    // cout << D[i] << endl;
    if(i==0) continue;
    ans2 += abs(D[i]-D[i-1]);
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
