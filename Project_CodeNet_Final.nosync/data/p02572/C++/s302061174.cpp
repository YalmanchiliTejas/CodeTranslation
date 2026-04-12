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



int main() {
  int N;
  cin >> N;
  ll A[N];
  ll cum[N];
  ll sum = 0;
  rep(i,N) {
	cin >> A[i];
	A[i] %= mod;
  }
  rep(i,N-1) {
	sum += A[N-i-1];
	sum %= mod;
	cum[N-i-2] = sum;
  }
  ll ans = 0;
  rep(i,N-1) {
	ans += A[i] * cum[i];
	ans %= mod;
  }
  cout << ans << endl;
}

