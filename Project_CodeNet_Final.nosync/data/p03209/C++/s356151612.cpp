//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
int n,x;
int sz[55],p[55];
int get(int len,int pos){
	if(pos==1)return len==0?1:0;
	if(pos<=1ll+sz[len-1]){
		return get(len-1,pos-1ll);
	}
	if(pos==2ll+sz[len-1]){
		return p[len-1]+1ll;
	}
	if(pos<=2ll+2ll*sz[len-1]){
		int ret=p[len-1]+1ll;
		return ret+get(len-1,pos-2ll-sz[len-1]);
	}
	return 1ll+p[len-1]+p[len-1];
}
signed main(){
	cin>>n>>x;
	sz[0]=1;p[0]=1;
	for(int i=1;i<=50;i++){
		sz[i]=sz[i-1]*2ll+3ll;
		p[i]=p[i-1]*2ll+1ll;
	}
	cout<<get(n,x)<<endl;
	return 0;
}