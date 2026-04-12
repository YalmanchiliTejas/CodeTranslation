#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,P> T;
typedef pair<int,ll> Pl;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)

const int SIZE = 1<<18;

struct BIT{
	int bit[SIZE+100];
	void add(int i,int x){
		while(i<=SIZE){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	int sum(int i){
		int res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	int sum(int l,int r){
		return sum(r)-sum(l-1);
	}
}bit;

struct segtree{
	int seg[SIZE*2];
	void set(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b){
			seg[k]=1;
			return;
		}else{
			if(k<SIZE-1){
				seg[k*2+1]|=seg[k];
				seg[k*2+2]|=seg[k];
			}
			seg[k]=0;
			set(a,b,k*2+1,l,(l+r)/2);
			set(a,b,k*2+2,(l+r)/2,r);
		}
	}
	bool changed(int k){
		k += SIZE-1;
		if(seg[k]==1)return true;
		while(k){
			k=(k-1)/2;
			if(seg[k]==1)return true;
		}
		return false;
	}
	void unset(int a,int k,int l,int r){
		if(r<=a||a<l)return;
		else if(a<=l&&r<=a+1){
			seg[k]=0;
			return;
		}else{
			if(k<SIZE-1){
				seg[k*2+1]|=seg[k];
				seg[k*2+2]|=seg[k];
			}
			seg[k]=0;
			unset(a,k*2+1,l,(l+r)/2);
			unset(a,k*2+2,(l+r)/2,r);
		}
	}
	void set(int a,int b){
		set(a,b,0,0,SIZE);
	}
	void unset(int a){
		unset(a,0,0,SIZE);
	}
}seg;

struct event{
	int y,l,r,type;
	event(int y,int l,int r,int type):y(y),l(l),r(r),type(type){}
	bool operator < (const event& a) const{
		if(y!=a.y)return y<a.y;
		return type < a.type;
	}
};

int W,H,N;
int A[100100],B[100100],C[100100],D[100100];
vector<int> zip;
ll ans = 0ll;
vector<event> ev;
set<int> s;

vector<int> uf,rank;
int touf[200100];
void fix(int k){
	if(seg.changed(k)){
		touf[k]=sz(uf);
		uf.pb(touf[k]);
		rank.pb(0);
		seg.unset(k);
	}
}
int find(int x){
	if(uf[x]==x)return x;
	return uf[x]=find(uf[x]);
}
void unite(int a,int b){
	a = find(a);
	b = find(b);
	if(a==b)return;
	//printf("unite %d %d\n",a,b);
	ans--;
	if(rank[a]<rank[b])uf[a]=b;
	else{
		uf[b]=a;
		if(rank[a]==rank[b])rank[a]++;
	}
}

/*void debug(event a){
	printf("%d %d %d %d\n",a.y,a.l,a.r,a.type);
}
void ds(){
	while(1){
		int t,a,b;
		cin >> t;
		if(t==0){
			cin >> a >> b;
			seg.set(a,b);
		}else if(t==1){
			cin >> a;
			seg.unset(a);
		}else{
			cin >> a;
			cout << seg.changed(a) << endl;
		}	
	}
}*/

int main(){
	scanf("%d %d %d",&W,&H,&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
		if(B[i]>D[i])swap(B[i],D[i]);
		if(A[i]>C[i])swap(A[i],C[i]);
	}
	A[N]=0;B[N]=0;C[N]=W;D[N]=0;
	A[N+1]=0;B[N+1]=0;C[N+1]=0;D[N+1]=H;
	A[N+2]=W;B[N+2]=0;C[N+2]=W;D[N+2]=H;
	A[N+3]=0;B[N+3]=H;C[N+3]=W;D[N+3]=H;
	N+=4;
	for(int i=0;i<N;i++){
		zip.pb(A[i]);zip.pb(C[i]);
	}
	zip.pb(-1); // for BIT
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	/*for(int i=0;i<zip.size();i++){
		printf("%d : %d\n",i,zip[i]);
	}*/
	for(int i=0;i<N;i++){
		A[i]=lower_bound(all(zip),A[i])-zip.begin();
		C[i]=lower_bound(all(zip),C[i])-zip.begin();
	}
	for(int i=0;i<N;i++){
		if(A[i]==C[i]){
			ev.pb(event(B[i],A[i],-1,0));
			ev.pb(event(D[i],A[i],-1,2));
		}else{
			ev.pb(event(B[i],A[i],C[i],1));
		}
	}
	s.insert(0);
	uf.pb(0);
	touf[0]=0;
	sort(all(ev));
	for(int i=0;i<ev.size();i++){
		event e = ev[i];
		//debug(e);
		if(e.type==0){
			int p = *(--s.lower_bound(e.l));
			//printf("p %d\n",p);
			fix(p);fix(e.l);
			touf[e.l]=touf[p];
			s.insert(e.l);
			bit.add(e.l,1);
		}else if(e.type==1){
			int num = bit.sum(e.l,e.r);
			//printf("num %d\n",num);
			if(num<=1)continue;
			ans += num-1;
			int L = e.l;
			int R = *(--s.upper_bound(e.r));
			seg.set(L,R);
		}else{
			int p = *(--s.lower_bound(e.l));
			fix(p);fix(e.l);
			unite(touf[p],touf[e.l]);
			s.erase(e.l);
			bit.add(e.l,-1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}