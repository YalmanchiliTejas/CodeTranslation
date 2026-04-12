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

vector<ll>a,p;//aはバーガーの総枚数,pはパティの枚数

ll rec(int n,ll x){
	if(n==0)return 1;
	ll res;
	if(x==1)res=0;//バンズ1枚
	else if(1<x&&x<=a[n-1]+1)res=rec(n-1,x-1);
	else if(x==a[n-1]+2)res=p[n-1]+1;
	else if(a[n-1]+2<x&&x<=2*a[n-1]+2)res=p[n-1]+1+rec(n-1,x-a[n-1]-2);
	else res=2*p[n-1]+1;
	return res;
}
 
void solve(){
	int n;
	ll x;
	cin>>n>>x;
	a.resize(n+1,1);
	p.resize(n+1,1);
	rep(i,n){
		a[i+1]=2*a[i]+3;
		p[i+1]=2*p[i]+1;
	}
	cout<<rec(n,x)<<"\n";
}
 
signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}