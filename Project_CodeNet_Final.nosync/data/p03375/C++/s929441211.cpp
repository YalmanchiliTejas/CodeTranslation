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

const int MC = 3003;
LL fct[MC+1];
LL invfct[MC+1];
int N;
LL M;
LL dp[MC][MC];

void build(){
	fct[0] = fct[1] = 1;
	repp(i,2,MC+1){
		fct[i] = fct[i-1] * i % M;
	}
	LL x = fct[MC];
	invfct[MC] = 1;
	for(int i = M - 2 ; i > 0 ; i >>= 1){
		if(i % 2 == 1) (invfct[MC] *= x) %= M;
		(x *= x) %= M;
	}
	repm(i,MC,0){
		invfct[i-1] = invfct[i] * i % M;
	}
}

int main(){
	cin >> N >> M;
	build();
	dp[0][0] = 1;
	repp(i,1,N+1){
		dp[i][0] = 1;
		repp(j,1,N+1) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * (j+1)) % M;
	} 
	LL ans = 0;
	LL p = 2 , q = 1;
	repm(i,N,-1){
		LL c = (i&1?M-1:1) * p % M * fct[N] % M * invfct[i] % M * invfct[N-i] % M;
		repp(j,0,N+1){
			(ans += dp[i][j] * c) %= M;
			c = c * q % M;
		}
		p = p * p % M;
		q = q * 2 % M;
	}
	cout << ans << endl;
	return 0;
}
