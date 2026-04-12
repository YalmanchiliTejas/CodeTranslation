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

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;cin>>n;
  vector<int> a(26,INF);
  vector<string> s(n);rep(i,n)cin>>s[i];
  
  rep(i,n){
    vector<int> tmp(26,0);
    rep(j,s[i].size()){
      ++tmp[s[i][j]-'a'];
    }
    rep(j,26){
      a[j] = min(tmp[j],a[j]);
    }
  }

  string ans = "";
  rep(i,26){
    rep(j,a[i]){
      ans += 'a'+i;
    }
  }

  print(ans);
  return 0;
}