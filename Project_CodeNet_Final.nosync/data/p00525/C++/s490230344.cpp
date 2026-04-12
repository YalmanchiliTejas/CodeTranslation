#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <chrono> //1e+9??§?????? auto end= chrono::system_clock::now()-st;  cout<<end.count()%1e+9<<endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef long double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(ll i=0;i<x;i++)
#define rep1(i,x) for(ll i=1;i<=x;i++)
#define rrep(i,x) for(ll i=x-1;i>=0;i--)
#define rrep1(i,x) for(ll i=x;i>0;i--)


ll W,H,N;
ll A[100004],B[100004],C[100004],D[100004];
vector<ll> xs,ys;
vector<ll> uf;
ll ans=0;
vector<ll> stev[200005];
vector<P> xev[200005];
vector<ll> enev[200005];
set<ll> s;
ll bit[100005];
const ll SIZE=1<<18;
ll id[SIZE];
bool flag[SIZE*2-1];

void renew(ll a,ll b,ll k,ll l,ll r){
	if(b<=l||r<=a) return;
	if(a<=l&&r<=b){
		flag[k]=1;
		return;
	}
	else{
		renew(a,b,k*2+1,l,(l+r)/2);
		renew(a,b,k*2+2,(l+r)/2,r);
		return;
	}
}

ll query(ll a,ll k,ll l,ll r){
	if(SIZE-1<=k){
		if(flag[k]){
			flag[k]=0;
			id[a]=uf.size();
			uf.pb(uf.size());
		}
		return id[a];
	}
	if(flag[k]){
		flag[k]=0;
		flag[k*2+1]=1;
		flag[k*2+2]=1;
	}
	if(a<(l+r)/2) return query(a,k*2+1,l,(l+r)/2);
	else return query(a,k*2+2,(l+r)/2,r);
}

void add(ll i,ll a){
	i++;
	while(i<=100004){
		bit[i]+=a;
		i+=(i&-i);
	}
}

ll sum(ll i){
	if(i==0) return 0;
	ll r=0;
	i++;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}

ll find(ll x){
	if(uf[x]==x) return x;
	return uf[x]=find(uf[x]);
}

void unite(ll x,ll y){
	//cout<<" "<<x<<"and"<<y<<endl;
	x=find(x);
	y=find(y);
	if(x!=y){
		ans--;
		//cout<<"m"<<endl;
	}
	uf[x]=y;
}

int main()
{
	cin>>W>>H>>N;
	xs.pb(-1);
	xs.pb(0);
	xs.pb(W);
	ys.pb(-1);
	ys.pb(0);
	ys.pb(H);
	rep(i,N){
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		if(A[i]>C[i]) swap(A[i],C[i]);
		if(B[i]>D[i]) swap(B[i],D[i]);
		if(A[i]==C[i]) xs.pb(A[i]);
		ys.pb(B[i]);
		ys.pb(D[i]);
	}
	A[N]=0; B[N]=0; C[N]=0; D[N]=H;
	A[N+1]=0; B[N+1]=0; C[N+1]=W; D[N+1]=0;
	A[N+2]=W; B[N+2]=0; C[N+2]=W; D[N+2]=H;
	A[N+3]=0; B[N+3]=H; C[N+3]=W; D[N+3]=H;
	N+=4;
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	ll ymax=0;
	rep(i,N){
		if(A[i]==C[i]){
			A[i]=C[i]=lower_bound(xs.begin(),xs.end(),A[i])-xs.begin();
			B[i]=lower_bound(ys.begin(),ys.end(),B[i])-ys.begin();
			D[i]=lower_bound(ys.begin(),ys.end(),D[i])-ys.begin();
			stev[B[i]].pb(A[i]);
			enev[D[i]].pb(A[i]);
			//cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<"a"<<endl;
			
		}
		else{
			A[i]=lower_bound(xs.begin(),xs.end(),A[i])-xs.begin();
			C[i]=upper_bound(xs.begin(),xs.end(),C[i])-xs.begin()-1;
			B[i]=D[i]=lower_bound(ys.begin(),ys.end(),B[i])-ys.begin();
			xev[B[i]].pb(P(A[i],C[i]));
			//cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<"b"<<endl;
		}
		ymax=max(ymax,max(B[i],D[i]));
	}
	ll l,r,bef;
	s.insert(0);
	uf.pb(0);
	rep(Y,ymax+1){
		rep(i,stev[Y].size()){
			bef=*--s.lower_bound(stev[Y][i]);
			query(bef,0,0,SIZE);
			query(stev[Y][i],0,0,SIZE);
			id[stev[Y][i]]=id[bef];
			add(stev[Y][i],1);
			s.insert(stev[Y][i]);
		}
		rep(i,xev[Y].size()){
			l=*s.lower_bound(xev[Y][i].fr); r=*--(s.upper_bound(xev[Y][i].sc));
			if(l<r){
				ans+= sum(r-1)-sum(l-1);
				//cout<<Y<<endl;
				//cout<<sum(r-1)-sum(l-1)<<endl<<endl;
				renew(l,r,0,0,SIZE);
			}
		}
		rep(i,enev[Y].size()){
			//cout<<Y;
			unite(query(*--( s.lower_bound(enev[Y][i]) ) ,0,0,SIZE) , query(  *(s.lower_bound(enev[Y][i])  ) ,0,0,SIZE ));
			add(enev[Y][i],-1);
			//cout<<endl;
			s.erase(enev[Y][i]);
		}
		//rep(i,enev[Y].size()) 
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}