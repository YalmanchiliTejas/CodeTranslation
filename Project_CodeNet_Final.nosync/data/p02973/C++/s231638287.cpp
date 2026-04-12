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

int main(){
	ll n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	multiset<ll>s;//同じ値でも違うグループになるためmultiset
	s.insert(a[0]);
	for(int i=1;i<n;++i){
		auto itr=s.lower_bound(a[i]);
		if(itr==s.begin()){//どのグループにも属さないので新しく作る
			s.insert(a[i]);
		}
		else {
			itr--;
			s.erase(itr);//大きいものから更新した方が有利
			s.insert(a[i]);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}


