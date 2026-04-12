#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define mem(i,a) memset(i,a,sizeof(i))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll INF=10000000000;
const int DMAX=600000+5;
const int MOD=6000000;
template<class T> inline void read(T &x){
    x=0; 
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
ll len[DMAX];
ll n,x;
ll full[DMAX];
ll solve(ll now,ll q){
	if(now==0){
		return 1;
	}
	if(q==1){
		return 0;
	}
	if(q>1 && q<len[now-1]+1){
		return solve(now-1,q-1);
	}
	if(q==len[now-1]+1){
		return full[now-1];
	}
	if(q==len[now-1]+2){
		return full[now-1]+1;
	}
	if(q>=len[now-1]+3 && q<len[now-1]*2+2){
		return full[now-1]+solve(now-1,q-1-len[now-1]-1)+1;
	}
	if(q>=len[now-1]*2+2){
		return full[now-1]*2+1;
	}
}
int main(){
	read(n),read(x);
	len[0]=1;
	full[0]=1;
	for(int i=1;i<=n;i++){
		len[i]=len[i-1]*2+3;
		full[i]=full[i-1]*2+1;
	}
	ll ans=solve(n,x);
	cout<<ans<<endl;
	return 0;
}