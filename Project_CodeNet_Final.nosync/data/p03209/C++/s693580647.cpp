#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll nlayer[55];
ll npaty[55];

ll paty(ll i, ll n){
  if(i==0)return 0;
  if(n==0)return 1;
  if(nlayer[n]/2+1==i){
    return 1+npaty[n-1];
  } else if(nlayer[n]/2+1>i){
    return paty(i-1, n-1);
  } else {
    return paty(i-(nlayer[n]/2+1), n-1)+1+npaty[n-1];
  }
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  
  nlayer[0]=1;
  npaty[0]=1;
  rep(i, n){
    nlayer[i+1]=2*nlayer[i]+3;
    npaty[i+1]=2*npaty[i]+1;
  }
  cout << paty(x, n) << endl;
  return 0;
}
