#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}

int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

ll N,K;


ll man(ll N, ll val) {
  //  cout << val << endl;
  if(N==0) return val;
  return min(man(N-1, val*2),man(N-1, val + K));

}

int main() {
  ll N;

  ll sum = 0;
  ll ans = 0;
  cin >> N;
  ll A[N];
  rep(i,N) {
	cin >> A[i];
	A[i] %= mod;
	sum += A[i];
	sum %= mod;
  }
  
  rep(i,N-1) {
	sum -= A[i];
	if(sum < 0) sum += mod;
	ans += A[i]*sum;
	ans %= mod;
  }
  cout << ans << endl;
}

