#include "bits/stdc++.h"
using namespace std;

using ll = long long;

template<typename T>
using vec = vector<T>;
template<typename T>
using mat = vector<vec<T>>;
template<typename T>
using val = valarray<T>;

using pi = pair<int,int>;

#define rep(a,b) for(int a=0; a<b; ++a)
#define Rep(a,b,c) for(int a=b; a<c; ++a)
#define all(v) v.begin(),v.end()

vec<int> divisor(int n){
	vec<int> ret;
	for(int i=1; i*i<=n; ++i){
		if(n%i==0){
			ret.emplace_back(i);
			if(i*i!=n) ret.emplace_back(n/i);
		}
	}
	sort(begin(ret),end(ret));
	return (ret);
}

int main(){
	int N; cin>>N;
	val<int> t(N);
	rep(i,N) cin>>t[i];
	auto div=divisor(t.max());
	int ans=0;
	rep(i,N){
		int p=lower_bound(all(div),t[i])-div.begin();
		ans+=(div[p]-t[i]);
	}
	cout<<ans<<endl;
}

