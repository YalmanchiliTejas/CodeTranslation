#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	string N; cin >> N;
	int D; cin >> D;
	const LL mod = 1e9+7;
	vector<LL> dp(D,0);
	LL z = 0;
	repp(t,0,N.size()){
		vector<LL> nx(D,0);
		repp(i,0,D) repp(k,0,10) (nx[(i+k)%D] += dp[i]) %= mod;
		repp(k,0,N[t]-'0') (nx[(z+k)%D] += 1) %= mod;
		z = (z+N[t]-'0')%D;
		swap(dp,nx);
	}
	if(z) dp[0] = (dp[0]+mod-1)%mod;
	cout << dp[0] << endl;
	return 0;
}
