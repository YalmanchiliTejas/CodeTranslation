/**
 * @File   : atcoder.cpp
 * @Author : pasnger 
 * @Date   : 29/8/2020, 2:59:47 pm 
 */

#include<bits/stdc++.h>
using namespace std;
#define INF 1e17
#define int long long
#define f(i, a, b) for(int i=a; i<b; i++)
#define rf(i, a, b) for(int i=a; i>b; i--)
const int mod = 1e9+7;

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__) 
void DBG() {
  cerr << "]\n";
}
template<typename T, typename ...Args> void DBG(T first, Args... args) {
  cerr << first; if (sizeof...(args))cerr<<", "; DBG(args...);
}

int mul(int x,int y){
    int res = x*y;
    if(res >= mod)res%=mod;
    return res;
}

int add(int x, int y){
    int res = x+y;
    if(res >= mod)res-=mod;
    return res;
}
int sub(int x, int y){
    int res = x-y;
    if(res<0)res+=mod;
    return res;
}

/////////////////////////// GLOBAL ///////////////////////////

/////////////////////////// GLOBAL ///////////////////////////

void solve() {
  int n;
  cin>>n;
  int arr[n];
  f(i, 0, n) cin>>arr[i];
  int s[n];
  rf(i, n-1, -1){
    s[i] = (i!=n-1? add(s[i+1], arr[i]): (arr[i]));
  }

  int p = 0;
  f(i, 0, n){
    p = add(p, mul(arr[i], sub(s[i], arr[i])));
  }

  cout<<p%mod<<"\n";
}


int32_t main() {
  #ifndef ONLINE_JUDGE
  clock_t tStart = clock();
  freopen("in.txt", "r", stdin);
  //freopen("output.txt","w",stdout);
  #endif 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  // cin >> t;
  for (int tt=1;tt<=t;tt++) {
    //cout << "Case #"<<tt<<": ";
    solve();
  }
  #ifndef ONLINE_JUDGE
    cerr << "\nRun Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC <<" sec\n";
  #endif
}
