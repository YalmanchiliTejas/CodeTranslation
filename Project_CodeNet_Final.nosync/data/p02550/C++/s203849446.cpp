#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn=200050;
unordered_map<int,int> mp;
ll sum[maxn];
ll n;
int x,mod;

void solve(){
	scanf("%lld %d %d",&n,&x,&mod);
	ll res=0;
	for(int i=1;i<=n;i++){
		if(mp.count(x)){
			res+=((n-i+1)/(i-mp[x]))*(sum[i-1]-((mp[x]-1>=0)?sum[mp[x]-1]:0));
			int now=mp[x];
			int ret=(n-i+1)%(i-mp[x]);
			for(int j=ret;j>0;j--){
				res+=sum[now]-(now-1>=0?sum[now-1]:0);
				now++;
			}
			break;
		}
		res+=x;
		sum[i]=sum[i-1]+x;mp[x]=i;
		x=(ll)x*x%mod;
	}
	printf("%lld\n",res);
}
int main(){
	solve();
	return 0;
}