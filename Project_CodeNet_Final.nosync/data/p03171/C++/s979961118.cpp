#include <bits/stdc++.h>
#define fore(x,a,b) for(int x=a, qwerty=b; x<qwerty; x++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
using namespace std;
typedef long long ll;
const int N=200500;
int n;
ll w[N];
ll dp[3005][3005];
ll f(int a, int b){
	if(a>b)return 0;
	ll &r=dp[a][b];
	if(r!=-1)return r;
	r=w[a]-f(a+1,b);
	r=max(r,w[b]-f(a,b-1));
	return r;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>w[i];
	memset(dp,-1,sizeof dp);
	cout<<f(0,n-1)<<"\n";
}