#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
 
 
#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};
 
//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL
 
struct Edge {
	ll from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;
 
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}

int memo[1 << 19][20] = {};
string s;
int n,N;
int p[1 << 19];

int rec(int l, int k){
  if(memo[l][k] == 0){ 
    if(k == 0){
      return memo[l][k] = p[l % N];
    }
    else{
      int a = max(rec(l,k-1), rec(l + (1 << k-1), k-1));
      int b = min(rec(l,k-1), rec(l + (1 << k-1), k-1));
      memo[l][k] = (s[a-b - 1] == '1' ? a : b);
    }
  }
  //printf("%d %d = %d\n",l,k,memo[l][k]);
  return memo[l][k];
}

int main(){
  cin >> n >> s;
  N = 1 << n;
  REP(i,N) scanf("%d",&p[i]);
  REP(i,N){
    printf("%d\n", rec(i, n));
  }
}
