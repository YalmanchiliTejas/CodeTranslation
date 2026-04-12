#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n,m,ans;
bool path[9][9],ch[9];

void dep(ll now,ll cnt){
	if(cnt==n){
		ans++;
		return;
	}
	for(int i=1;i<n;i++){
		if(path[now][i]==false){
			continue;
		}
		if(ch[i]==true){
			continue;
		}
		ch[i]=true;
		dep(i,cnt+1);
		ch[i]=false;
	}
}
int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		path[x][y]=path[y][x]=true;
	}
	ch[0]=true;
	dep(0,1);
	cout << ans;
	return 0;
}