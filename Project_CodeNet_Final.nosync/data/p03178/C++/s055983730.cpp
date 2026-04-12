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

const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b; if(a>=MOD)a-=MOD; return a;}
ll sub(ll a, ll b){a-=b; if(a<0)a+=MOD; return a;}

const int N=1e4+5, D=101;
ll dp[N][D][2];
int nxt[D][10], d;
string n;
ll f(int i, int j, int b){
	if(i==SZ(n))return j == 0;
	ll &r=dp[i][j][b];
	if(r!=-1)return r;
	r=0;
	for(int c=b?9:n[i]; c>=0; c--)r=add(r,f(i+1,nxt[j][c],c<n[i]||b));
	return r;
}

int main(){FIN;mset(dp,-1);
	cin >> n >> d;
	fore(x,0,SZ(n))n[x]-='0';
	fore(x,0,d)fore(c,0,10)nxt[x][c]=(x+c)%d;
	cout << sub(f(0,0,0),1) << "\n";
}