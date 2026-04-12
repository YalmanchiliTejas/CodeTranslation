#include<bits/stdc++.h>
using namespace std;

#define CO const
#define IN inline
typedef long long int64;

template<class T> IN T read(){
	T x=0,w=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-') w=-w;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*w;
}
template<class T> IN T read(T&x){
	return x=read<T>();
}

CO int mod=1e9+7,i2=(mod+1)/2;
IN int add(int a,int b){
	return (a+=b)>=mod?a-mod:a;
}
IN int mul(int a,int b){
	return (int64)a*b%mod;
}
IN int fpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1) ans=mul(ans,a);
	return ans;
}

CO int N=110;
int n;
namespace seg{
	pair<int,int> val[4*N];
	
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void build(int x,int l,int r){
		if(l==r) {val[x]={read<int>(),l}; return;}
		build(lc,l,mid),build(rc,mid+1,r);
		val[x]=min(val[lc],val[rc]);
	}
	pair<int,int> query(int x,int l,int r,int ql,int qr){
		if(ql<=l and r<=qr) return val[x];
		if(qr<=mid) return query(lc,l,mid,ql,qr);
		if(ql>mid) return query(rc,mid+1,r,ql,qr);
		return min(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
	}
	#undef lc
	#undef rc
	#undef mid
}

int num,L[N],R[N],H[N];
vector<int> to[N];

int build(int l,int r){
	int x=++num;
	L[x]=l,R[x]=r,H[x]=seg::query(1,1,n,l,r).first;
	vector<int> pos;
	for(int i=l;i<=r;){
		pair<int,int> v=seg::query(1,1,n,i,r);
		if(v.first>H[x]) break;
		pos.push_back(v.second);
		i=v.second+1;
	}
	pos.push_back(r+1);
	int last=l-1;
	for(int now:pos){
		if(last+1<=now-1){
			to[x].push_back(build(last+1,now-1));
			H[to[x].back()]-=H[x];
		}
		last=now;
	}
	return x;
}

int F[N][2],coef=1;

void dfs(int x){
//	cerr<<x<<" "<<L[x]<<" "<<R[x]<<" H="<<H[x]<<endl;
	int len=R[x]-L[x]+1;
	for(int y:to[x]) dfs(y),len-=R[y]-L[y]+1;
	F[x][0]=fpow(2,len),F[x][1]=2;
	for(int y:to[x]){
		F[x][0]=mul(F[x][0],add(F[y][0],mul(2,F[y][1])));
		F[x][1]=mul(F[x][1],F[y][1]);
	}
	F[x][0]=add(F[x][0],mod-F[x][1]);
	F[x][1]=mul(F[x][1],fpow(2,H[x]-1));
//	cerr<<x<<" F="<<F[x][0]<<" "<<F[x][1]<<endl;
}

int main(){
	read(n);
	seg::build(1,1,n);
	int root=build(1,n);
	dfs(root);
	int ans=add(F[root][0],F[root][1]);
	ans=mul(ans,coef);
	printf("%d\n",ans);
	return 0;
}
