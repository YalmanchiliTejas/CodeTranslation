#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
#define rep(i,n) for(int i = 0;i < ((int)(n));++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SUM(vec) accumulate(all(vec),0LL)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define test(a) cout<<"line:"<<__LINE__<<"["<<(#a)<<": "<<(a)<<"]"<<endl

const int INF = 1e9+7;
const ll INFL = 9*1e18;

ll inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;}
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;}
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;}

int ctoi(char c){return c - '0';}

bool isOk(ll key,ll value){
  return key >= value;
}

ll binary_search(vector<ll> a,ll key){
  ll ok = a.size()-1;
  ll ng = 0;

  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(isOk(key,a[mid]))ok = mid;
    else ng = mid;
  }
  return ok;
}

bool isPrime(ll n) {
	for (int i = 2; n >= i * i; ++i) {
		if(!(n % i))return false;
	}
  return true;
}
vector<ll> primes(ll n){
  vector<ll> v(1,1);
  for (ll i = 2; n >= i * i; ++i) {
		if(!(n % i)){
      v.pb(i);
	  }
  }
  if(v.size()==1)v.pb(n);
  return v;
}


int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;cin>>n;
  string s;cin>>s;
  int k;cin>>k;
  char c = s[k-1];
  rep(i,n){
    if(s[i] != c)s[i] = '*';
  }
  print(s);
  return 0;
} 