#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const long inf=1e16;
int main(){
	int N;cin>>N;
	long A[N];
	rep(i,0,N) cin>>A[i];
	long dp[N][2] = {};
    dp[0][0] = 0; dp[0][1] = A[0];
    dp[1][0] = 0; dp[1][1] = A[1];
	rep(i,2,N)rep(j,0,2){
		int s = i / 2 + j - 1;
        long res = -inf;
		rep(k,2,min(3, i) + 1){
            int t = s - (i-k) / 2;
			if(0 <= t && t < 2) res = max(res, dp[i-k][t]);
		}
        if(res == -inf) res = 0;
		dp[i][j] = res + A[i];
	}
    if(N % 2 == 0) cout<<max(dp[N-2][1], dp[N-1][1])<<endl;
    else cout<<max(dp[N-3][1], max(dp[N-2][1], dp[N-1][0]))<<endl;
}