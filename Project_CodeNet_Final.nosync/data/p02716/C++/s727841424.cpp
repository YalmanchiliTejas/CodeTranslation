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
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

int main(){
  int N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  ll ans = 0;
  const ll mini = -1e17;
  if(N%2==0){
    vector<ll> dp00(N+1, 0), dp01(N+1, 0), dp10(N+1, 0), dp11(N+1, 0);
    rep(i,N){
      dp00[i+1] = i%2? dp01[i] : -mini;
      dp01[i+1] = i%2? -mini: dp00[i]+A[i];
      dp10[i+1] = max(dp00[i], dp11[i]);
      dp11[i+1] = i>0? dp10[i]+A[i]: -mini;
    }

    ans = max(dp00[N], dp11[N]);
  }
  else{
    vector<ll> dp00(N+1, 0), dp01(N+1, 0), dp10(N+1, 0), dp11(N+1, 0), dp20(N+1, 0), dp21(N+1, 0);

    rep(i,N){
      dp00[i+1] = i%2? dp01[i] : mini;
      dp01[i+1] = i%2? mini: dp00[i] + A[i];
      dp10[i+1] = max(dp00[i], dp11[i]);
      dp11[i+1] = i>0? dp10[i]+A[i]: mini;
      dp20[i+1] = max(dp10[i], dp21[i]);
      dp21[i+1] = i>1? dp20[i]+A[i]: mini;
    }
    /*
    rep(i,N+1) cout << dp00[i] << " ";
    cout << endl;
    rep(i,N+1) cout << dp01[i] << " ";
    cout << endl;
    rep(i,N+1) cout << dp10[i] << " ";
    cout << endl;
    rep(i,N+1) cout << dp11[i] << " ";
    cout << endl;
    rep(i,N+1) cout << dp20[i] << " ";
    cout << endl;
    rep(i,N+1) cout << dp21[i] << " ";
    cout << endl;
    */

    ans = max({dp21[N], dp10[N]});
  }
  cout << ans << endl;
  return 0;
}
