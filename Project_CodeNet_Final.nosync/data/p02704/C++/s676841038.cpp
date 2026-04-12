#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const int N = 500, MX = 64;

ull ans[N][N], tans[N][N];
ull r[N],rt[N],c[N],ct[N];
int lr[N],lc[N];
int n;

ull op(ull cur, ull nxt, ull o){
	if(o == 0)return cur & nxt;
	else return cur | nxt;
}

void solve_layer(int l){
	rep(i,0,n)lr[i] = (r[i]>>l)&1LL;
	rep(i,0,n)lc[i] = (c[i]>>l)&1LL;
	vector<int> cnt(n,0);
	rep(i,0,n){
		rep(j,0,n)tans[i][j] = lr[i];
	}

	rep(j,0,n){
		if(lc[j] ^ ct[j]){
			rep(i,0,n)tans[i][j] = lc[j];
		}
	}

	rep(i,0,n){
		rep(j,0,n)cnt[i] += tans[i][j];
	}

	rep(j,0,n){
		int cur = tans[0][j];
		rep(i,1,n)cur = op(cur, tans[i][j], ct[j]);	
		if(cur != lc[j]){
			rep(i,0,n){
				if((rt[i] ^ lr[i]) == 0){
					int ed = tans[i][j]?-1:1;
					if(!(cnt[i] + ed == n && lr[i] == 0) && !(cnt[i] + ed == 0 && lr[i]==1)){
						cnt[i] += ed;
						tans[i][j] ^= 1;
						break;
					}
				}
			}
		}
	}

	rep(i,0,n)rep(j,0,n)assert(tans[i][j] >= 0 && tans[i][j] <= 1);
	rep(i,0,n)rep(j,0,n)ans[i][j] += (1ULL << l) * tans[i][j];
}

bool check_valid(){
	bool valid = 1;		
	rep(i,0,n){
		ull cur = ans[i][0];
		rep(j,1,n){
			cur = op(cur,ans[i][j],rt[i]);
		}
		valid &= cur == r[i];
	}
	rep(i,0,n){
		ull cur = ans[0][i];
		rep(j,1,n){
			cur = op(cur,ans[j][i],ct[i]);
		}
		valid &= cur == c[i];
	}
	return valid;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	rep(i,0,n)cin >> rt[i];
	rep(i,0,n)cin >> ct[i];
	rep(i,0,n)cin >> r[i];
	rep(i,0,n)cin >> c[i];
	rep(i,0,MX)solve_layer(i);
	if(check_valid()){
		rep(i,0,n){
			rep(j,0,n){
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else{
		cout << -1 << '\n';
	}
}
