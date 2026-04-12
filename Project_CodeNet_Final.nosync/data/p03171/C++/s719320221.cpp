#include <bits/stdc++.h>
#ifdef DBP
#define deb(...) fprintf(stderr,__VA_ARGS__)
#else
#define deb(...) 0
#endif
#define fst first
#define snd second
#define fore(x,a,b) for(int x=(a), qwerty=(b); x<qwerty; x++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int N=3005;
ll dp[N][N],A[N];
int n;

ll f(int i, int j){
	if(i==j)return 0;
	ll &r=dp[i][j];
	if(r!=-1)return r;
	int w=(n-(j-i))&1;
	if(w==0)r=max(f(i+1,j)+A[i],f(i,j-1)+A[j-1]);
	else r=min(f(i+1,j),f(i,j-1));
	return r;
}

int main(){FIN;mset(dp,-1);
	cin >> n;
	fore(x,0,n)cin>>A[x];
	cout << 2LL*f(0,n) - accumulate(A,A+n,0LL) << "\n";
}