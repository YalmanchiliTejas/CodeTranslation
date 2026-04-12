#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

bool a[9][9],vis[9];
ll ans,n,m;

void dep(ll now ,ll cnt){
	if(cnt==n){
		ans++;
		return;
	}
	for(int i=0;i<n;i++){
		if(a[now][i]==0){
			continue;
		}
		if(vis[i]==1){
			continue;
		}
		vis[i]=1;cnt++;
		dep(i,cnt);
		vis[i]=0;cnt--;
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		a[l][r]=a[r][l]=1;
	}
	vis[0]=1;
	dep(0,1);
	cout <<ans;
}