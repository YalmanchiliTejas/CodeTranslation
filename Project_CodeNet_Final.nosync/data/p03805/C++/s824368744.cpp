#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int p[10];
int n,m;
int ans=0;
vector<vector<bool>> a(10,vector<bool>(10,false));

void dfs(int pos,int mask){
	if(pos==n){
		if(p[0]==0){
			bool flg=true;
			rep(i,n-1){
				if(!(a[p[i]][p[i+1]] || a[p[i+1]][p[i]])) flg=false;
			}
			if(flg) ans++;
		}
		return;
	}
	rep(i,n){
		if(mask&(1<<i)){
			p[pos]=i;
			dfs(pos+1,(mask^(1<<i)));
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i,m){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		a[x][y]=true;
		a[y][x]=true;
	}
	dfs(0,(1<<n)-1);
	cout << ans << endl;
}