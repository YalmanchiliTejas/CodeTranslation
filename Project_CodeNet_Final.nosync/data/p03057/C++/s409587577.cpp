#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=2e5+10,mo=1e9+7;
ll f[N],n,m,lim,q[N];
char s[N];
void move(ll &a,ll b){a=(a+b)%mo;}
int main(){
	cin>>n>>m;
	scanf("%s",s+1);
	if (s[1]=='B'){
		for (ll i=1;i<=m;i++)s[i]='B'+'R'-s[i];
	}
	ll cnt=0;
	for (ll i=1;i<=m;i++){
		if (s[i]=='R')cnt++;
		else {
			if (!lim)lim=cnt|1;
			else if (cnt&1)lim=min(lim,cnt);
			cnt=0;
		}
	}
	if (!lim){
		for (int i=1;i<=n;i++){
			move(f[i],q[i-2]+i-(i==1));
			q[i]=(q[i-1]+f[i])%mo;
		}
		cout<<f[n]+1<<endl;
		return 0;
	}
	lim++;
	for (ll i=1;i<=n;i++){
		f[i]=q[i-2];
		if (i<=lim&&(i%2==0))move(f[i],i);
		q[i]=((ll)q[i-2]+f[i]-(i>lim?f[i-lim]:0)+mo)%mo;
	}
	cout<<f[n]<<endl;
}