#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const array<pair<int,int>,4> fd{make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
//ll

ll p[51],m[51];
ll ans = 0;

ll f(int n, ll x){
  if(x<=0)return 0;
  if(n==0)return 1;
  if(x == m[n]){
    return p[n];
  }else if(x<=m[n]/2){
    return f(n-1,x-1);
  }else{
    return p[n-1] + 1 + f(n-1,x-m[n]/2-1);
  }
}

int main(){
  int n;cin>>n;
  ll x;cin>>x;
  p[0] = m[0] = 1;
  repd(i,1,51){
    p[i] = 1+p[i-1]*2;
    m[i] = 3+m[i-1]*2;
  }
  cout << f(n,x) << endl;

}

