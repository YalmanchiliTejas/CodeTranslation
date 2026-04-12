#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll n,x,m;
int cnt,cnt2;
int ha[100005];
map<int,int> pre;
int main(){
	cin>>n>>x>>m;
	ll now=x;
	pre[x]=1;ha[1]=x;
	for(int i=2;i<=2*m+1;i++) {
		now = now * now % m;
		if (pre.find(now) != pre.end()) {
			cnt = i-1;
			cnt2=pre[now]-1;
			break;
		} else
			pre[now] = i, ha[i] = now;
	}
	ll ans=0;
	for(int i=1;i<=min(n,(ll)cnt2);i++) ans+=ha[i];
	ll ans2=0;
	for(int i=1;i<=((n-cnt2)<0?0:cnt-cnt2);i++) ans2+=ha[i+cnt2];
	ans2=ans2*(max(0ll,(n-cnt2)/(cnt-cnt2)));
	for(int i=1;i<=max(0ll,(n-cnt2)%(cnt-cnt2));i++) ans+=ha[i+cnt2];
	cout<<ans+ans2<<endl;
	return 0;
}
