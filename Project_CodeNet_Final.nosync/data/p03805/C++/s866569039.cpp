#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n,m,ans;
bool r[10][10],ch[9];
void dep(ll now,ll cnt){
	ch[now]=true;
	if(cnt==n){
		ans++;
	}
	for(ll i=0;i<n;i++){
		if(r[now][i]==false){
			continue;
		}
		if(ch[i]){
			continue;
		}
		ch[i]=true;
		dep(i,cnt+1);
		ch[i]=false;
	}
}
int main() {
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		r[x][y]=true;
		r[y][x]=true;
	}
	dep(0,1);
	cout <<ans;
	// your code goes here
	return 0;
}