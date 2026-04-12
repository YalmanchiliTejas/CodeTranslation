#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
char s[110];
ll dp[110][5][2];// = / <
int main() {
	scanf("%s",s+1);
	int k=read(),n=strlen(s+1);
	dp[0][0][0]=1;
	rep(i,0,n) rep(j,0,k) rep(c,0,1) {
		ll& ans=dp[i][j][c];
		if(!ans) continue;
	//	printf("%d %d %d : %lld\n",i,j,c,ans);
		rep(x,0,9) {
			if(!x) dp[i+1][j][c|(x+'0'<s[i+1])]+=ans;
			else if(x+'0'<=s[i+1]||c) {
				dp[i+1][j+1][c|(x+'0'<s[i+1])]+=ans;
			}
		}
	}
	printf("%lld\n",dp[n][k][0]+dp[n][k][1]);
	return 0;
}
