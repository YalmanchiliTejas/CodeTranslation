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
	int N; cin >> N;
	vector<LL> a(N);
	repp(i,0,N) cin >> a[i];
	vector<vector<LL>> dp(N,vector<LL>(N,0));
	repp(i,0,N) dp[i][i] = a[i];
	repp(d,1,N) repp(i,0,N-d){
		int j = i+d;
		if(d&1){
			dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
		} else {
			dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
		}
	}
	cout << dp[0][N-1]*(N%2==0?-1:1) << endl;
	return 0;
}
