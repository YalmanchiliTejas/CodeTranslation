#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
    ll n,x,m;cin>>n>>x>>m;
    if(n==1) return cout<<x<<'\n',0;
    map<int,ll> pos,ps;
    pos[x]=1;ps[1]=x;
    ll now=x,sum=x;
    for(int i=2;i<=m+2;i++) {
    	now=now*now%m;sum+=now;
    	if(i==n) return cout<<sum<<endl,0;
    	if(pos[now]) {
    		ll need=n-pos[now]+1;
    		ll circle=i-pos[now];
    		return cout<<ps[pos[now]-1]+need/circle*(sum-ps[pos[now]])+ps[pos[now]+need%circle-1]-ps[pos[now]-1],0;
    	}else {
    		pos[now]=i;
    		ps[i]=sum;
    	}
    }
    return 0;
}