#include<bits/stdc++.h>
using namespace std;
#define maxn 120
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

const ll mod = 1e9 + 7;
int h[maxn],a[maxn],tag[maxn],r[maxn * maxn],tot,n;
ll f[maxn][2][2][2],rec[maxn * maxn][2][2][2];

inline void up(ll &x,ll y){ x = (x + y) % mod; }
inline ll power(ll x,ll y){
	ll res = 1;
	if ( y < 0 ) return 1;
	while ( y ){
		if ( y & 1 ) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int main(){
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&h[i]) , a[i] = h[i];
	a[n + 1] = 1;
	sort(a + 1,a + n + 2);
	repd(l,n + 1,1){
		if ( a[l] == a[l + 1] ) continue;
		int curh = a[l],last = 0,t = (a[l + 1] - a[l]) & 1; ll curp = power(2,a[l + 1] - a[l] - 1);
		memset(f,0,sizeof(f));
		for (register int i = 1 ; i <= n ; ){
			if ( h[i] >= curh && h[i - 1] >= curh ){
				int nxt;
				if ( tag[i] ){
					nxt = r[tag[i]];
					rep(x,0,1) rep(y,0,1) rep(cx,0,1) rep(cy,0,1){
						if ( y != cx ){
							up(f[nxt][x][cy][1],f[i - 1][x][y][1] * (rec[tag[i]][cx][cy][1] + rec[tag[i]][cy][cx][1]) % mod * curp);
							up(f[nxt][x][cy][0],f[i - 1][x][y][0] * (rec[tag[i]][cx][cy][1] + rec[tag[i]][cy][cx][1]) % mod * curp);
							up(f[nxt][x][cy][0],(f[i - 1][x][y][0] + f[i - 1][x][y][1]) * rec[tag[i]][cx ^ t][cy ^ t][0]);
						}
						else{
							up(f[nxt][x][cy][0],(f[i - 1][x][y][0] + f[i - 1][x][y][1]) * rec[tag[i]][cx ^ t][cy ^ t][0]);
							up(f[nxt][x][cy][0],(f[i - 1][x][y][0] + f[i - 1][x][y][1]) * (rec[tag[i]][cx][cy][1] + rec[tag[i]][cy][cx][1]) % mod * curp);	
						}
					}
				}
				else{
					nxt = i;
					rep(x,0,1) rep(y,0,1) rep(z,0,1) rep(c,0,1){
						up(f[nxt][x][c][z && (c != y)],f[i - 1][x][y][z]);
					}
				}
				i = nxt + 1;
			}
			else if ( h[i] < curh && h[i - 1] >= curh ){
				tag[last] = ++tot , r[tot] = i - 1;
				rep(x,0,1) rep(y,0,1) rep(z,0,1) rec[tot][x][y][z] = f[i - 1][x][y][z];
				i++;
			}
			else if ( h[i] >= curh && h[i - 1] < curh ){
				last = i;
				int nxt;
				if ( tag[i] ){
					nxt = r[tag[i]];
					rep(x,0,1) rep(y,0,1){
						f[nxt][x][y][0] = rec[tag[i]][x ^ t][y ^ t][0];
						f[nxt][x][y][1] = (rec[tag[i]][y][x][1] + rec[tag[i]][x][y][1]) * curp % mod;
					}
				}
				else{
					nxt = i;
					rep(c,0,1) f[i][c][c][1] = 1;
				}
				i = nxt + 1;
			}
			else i++;
		}
		if ( h[n] >= curh ){
			tag[last] = ++tot , r[tot] = n;
			rep(x,0,1) rep(y,0,1) rep(z,0,1) rec[tot][x][y][z] = f[n][x][y][z];
		}
	}
	ll ans = 0;
	rep(x,0,1) rep(y,0,1) rep(z,0,1) up(ans,f[n][x][y][z]);
	printf("%lld\n",ans);
}
