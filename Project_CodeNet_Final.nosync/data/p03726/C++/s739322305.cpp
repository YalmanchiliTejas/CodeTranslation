    #include <bits/stdc++.h>
    #define N 100005
    #define ll long long
    #define For(i,x,y) for(int i=(x);i<=(y);++i)
    #define Rof(i,x,y) for(int i=(x);i>=(y);--i)
    #define Edge(x) for(int i=head[x];i;i=e[i].nxt)
    #define mset(x,y) memset(x,y,sizeof(x))
    #define strL strlen
    #define p_b push_back
    #define mcpy(x,y) memcpy(x,y,sizeof(x))
    #define lson l,mid,(o<<1)
    #define rson mid+1,r,((o<<1)|1)
    #define Ls (t[o].ls)
    #define Rs (t[o].rs)
    #define mod
    #define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
    using namespace std;
    vector<int> g[N];
    int mch[N];
    void dfs(int x,int f){
    	for(auto to:g[x])
    		if(to!=f){
    			dfs(to,x);
    			if(!mch[to]) mch[x]=to,mch[to]=x;
    		}
    	if(!mch[x]){
    		if(mch[f] || f==0){
    			puts("First");
    			exit(0);
    		} 
    		mch[x]=f,mch[f]=x;
    	}
    }
    int main(){
    	int n,u,v;
    	scanf("%d",&n);
    	if(n==1) return puts("First"),0;
    	For(i,1,n-1){
    		scanf("%d%d",&u,&v);
    		g[u].push_back(v),g[v].push_back(u);
    	}
    	dfs(1,0);
    	puts("Second");
    }