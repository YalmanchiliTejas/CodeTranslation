#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=998244353;
const int siz=1e5;
const long inf=1e9;
int main(){
	int N,S; cin>>N>>S;
	int a;
	long ans = 0, res;
    long dp[N+1][S+1] = {}; dp[0][0] = 1;
	rep(i,0,N){
		cin>>a;
		rep(j,0,S+1){
            if(j < a) res = 0;
            else if(j == a) res = i + 1;
			else res = dp[i][j-a];
			if(j == S) (ans += res * (N - i)) %= mod;
            dp[i+1][j] = (dp[i][j] + res) % mod;
		}
	}cout<<ans<<endl;
}