#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fi first
#define se second
using ll=long long int;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

//LIS,最長増加部分列
template<typename T>
T LIS (T N){
	T INF = numeric_limits<T>::max();
	vector<T>a(N);
	for (long long i = 0; i < N;++i){
		cin >> a[i];
		a[i]=-a[i];
	}
	vector<T>dp(N, INF);//最後がaiの最長増加部分列の長さ
	for (long long i = 0; i < N;++i) {
		*upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main(){
	ll n;
	cin>>n;
	ll cnt=1;
	vector<ll>a(n);
	ll maxv=0;
	cout<<LIS<ll>(n)<<endl;
	
	return 0;
}


