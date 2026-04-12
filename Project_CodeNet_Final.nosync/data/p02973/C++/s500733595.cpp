#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
#define INF 1e+9
#define MAX_N 200000

int dp[MAX_N];
int n;
vector<int> a;

int lis() {
    fill(dp, dp+n, INF);
    for (int i=0; i<n; ++i) {
        *upper_bound(dp, dp+n, a[i]) = a[i];
    }
    return lower_bound(dp, dp+n, INF) - dp;
}


int main(){
  cin >> n;
  a.resize(n);
  rep(i,n)cin >> a[n-i-1];
  int u=a[0];
  int o=0;
  rep(i,n-1)if(u!=a[i+1])o++;
  if(o==0){
    cout << n << endl;
    return 0;
  }
  
  cout << lis() << endl;
}
