#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;
//ここから

//LIS,最長増加部分列
template<typename T>
T LIS (int N,vector<T> &a){
	T INF = numeric_limits<T>::max();
	vector<T>dp(N+5, INF);//最後がaiの最長増加部分列の長さ
	for (int i = N-1; i >=0;--i) {
		*upper_bound(dp.begin(), dp.end(), a[i]) = a[i];//広義ならupper_boundに変える
	}
	int ans=lower_bound(dp.begin(), dp.end(), INF)-dp.begin();
  return ans;
}

void solve(){
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  ll ans=LIS(n,a);
  cout<<ans;
  
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
