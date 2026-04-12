#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

int main(){//解説参考. 数列Aの講義単調減少数列の最長を求める.
	int n;
	cin>>n;
	
	vi v;
	REP(i,n){
		int a;
		cin>>a;
		
		auto p=upper_bound(ALL(v),-a);
		if(p==v.end()) v.push_back(-a);
		else *p=-a;
	}
	
	cout<<v.size()<<endl;
}