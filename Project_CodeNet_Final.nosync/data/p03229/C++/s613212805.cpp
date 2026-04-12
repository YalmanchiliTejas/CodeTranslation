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
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<typename T>void chmax(T &a,T b){a=max(a,b);}
template<typename T>void chmin(T &a,T b){a=min(a,b);}
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	//ジグザグ
	sort(begin(a),end(a));
	ll sum=0;
	if(n%2==0){
		rep(i,(n-1)/2){
			sum+=2*a[n-1-i];
			sum-=2*a[i];
		}
		sum+=a[n/2];sum-=a[n/2-1];
	}
	else {//nが奇数のときは注意
		rep(i,(n-3)/2)sum+=2*a[n-1-i];
		rep(i,(n-1)/2)sum-=2*a[i];
		sum+=a[n/2+1];sum+=a[n/2];
		ll cmp=0;
		rep(i,(n-1)/2)cmp+=2*a[n-1-i];
		rep(i,(n-3)/2)cmp-=2*a[i];
		cmp-=a[n/2];cmp-=a[n/2-1];
		sum=max(sum,cmp);
	}
	//a1<=a2>=a3...とa1>=a2<=a3...となるものを考える
	cout<<sum<<"\n";
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
