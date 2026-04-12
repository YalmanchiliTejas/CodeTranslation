#include <cstdio>
#include <cstdlib>
#include <climits>

const int MAXN=200005;
int a[MAXN];

class FHQ_Treap{
	private:
		int rt;
		struct node{int val,key,sz,ls,rs;}d[MAXN<<2];
		struct dual_rt{
			int lrt,rrt;
			dual_rt(){lrt=rrt=0;}
		};
		void upd(int u){
			d[u].sz=d[d[u].ls].sz+d[d[u].rs].sz+1;
		}
		int new_nd(int val){
			static int cnt=0;
			d[++cnt]=(node){val,rand(),1};
			return cnt;
		}
		dual_rt split(int u,int val){
			dual_rt ret;
			if(!u) return ret;
			if(val<d[u].val){
				ret=split(d[u].ls,val);
				d[u].ls=ret.rrt;
				ret.rrt=u;
			}
			else{
				ret=split(d[u].rs,val);
				d[u].rs=ret.lrt;
				ret.lrt=u;
			}
			upd(u);
			return ret;
		}
		int merge(int u,int v){
			if(!u || !v) return u|v;
			if(d[u].key<d[v].key){
				d[u].rs=merge(d[u].rs,v);
				upd(u);
				return u;
			}
			else{
				d[v].ls=merge(u,d[v].ls);
				upd(v);
				return v;
			}
		}
		int kth_val(int u,int k){
			while(true){
				if(k>d[d[u].ls].sz+1){
					k-=d[d[u].ls].sz+1;
					u=d[u].rs;
				}
				else if(k<=d[d[u].ls].sz)
					u=d[u].ls;
				else return d[u].val;
			}
		}
	public:
		void ist(int val){
			dual_rt x=split(rt,val);
			rt=merge(merge(x.lrt,new_nd(val)),x.rrt);
		}
		void del(int val){
			dual_rt x=split(rt,val);
			dual_rt y=split(x.lrt,val-1);
			y.rrt=merge(d[y.rrt].ls,d[y.rrt].rs);
			rt=merge(merge(y.lrt,y.rrt),x.rrt);
		}
		int kth_val(int k){return kth_val(rt,k);}
}T;

int main(){
	srand((size_t)new(char));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		T.ist(a[i]);
	}
	for(int i=1;i<=n;++i){
		T.del(a[i]);
		printf("%d\n",T.kth_val(n>>1));
		T.ist(a[i]);
	}
	return 0;
}