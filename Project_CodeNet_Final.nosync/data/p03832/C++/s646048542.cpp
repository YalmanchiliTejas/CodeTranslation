#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define Fst first
#define Snd second
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repv(t,it,v) for(vector<t>::iterator it = v.begin() ; it != v.end() ; ++it)

typedef long long LL;

int N,A,B,C,D;
LL mod = 1e9 + 7;
LL con[1010][1010];
LL dp[1010][1010];
LL r[1010];

int main(){
	scanf("%d%d%d%d%d" , &N , &A , &B , &C , &D);
	con[0][0] = 1;
	repp(i,1,N+1){
		con[i][0] = con[i][i] = 1;
		repp(j,1,i){
			con[i][j] = (con[i-1][j-1] + con[i-1][j]) % mod;
		}
	}
	{
		int x = mod - 2;
		r[N] = 1;
		repp(i,2,N+1){
			(r[N] *= i) %= mod;
		}
		LL y = r[N];
		r[N] = 1;
		while(x > 0){
			if(x%2==1) (r[N] *= y) %= mod;
			(y *= y) %= mod;
			x /= 2;
		}
	}
	repm(i,N,0){
		r[i-1] = r[i] * i % mod;
	}
	dp[0][A-1] = 1;
	repp(i,0,N+1){
		repp(j,A,B+1){
			(dp[i][j] += dp[i][j-1]) %= mod;
			if(i+j*C>N) continue;
			LL z = 1;
			repp(k,0,C){
				(z *= con[N-i-j*k][j]) %= mod;
			}
			repp(k,C,D){
				dp[i+j*k][j+1] += dp[i][j] * z % mod * r[k] % mod;
				if(i+j+j*k>N) break;
				(z *= con[N-i-j*k][j]) %= mod;
			}
			if(i+j*D<=N) dp[i+j*D][j+1] += dp[i][j] * z % mod * r[D] % mod;
		}
	}
	printf("%lld\n" , (dp[N][B] + dp[N][B+1]) % mod);
	return 0;
}
