#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int,int> P;

const int N=2e5+5;
const int INF=numeric_limits<int>::max();
int n,x[N],y[N],mn[N],mx[N];
set<P> Smin,Smax;
P Rx,Rn,Bx,Bn;

void del(int id){
	Smin.erase({mn[id],id});
	Smax.erase({mx[id],id});
}

void add(int id){
	Smin.emplace(mn[id],id);
	Smax.emplace(mx[id],id);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
		mn[i]=min(x[i],y[i]);
		mx[i]=max(x[i],y[i]);
		Smin.emplace(mn[i],i);
		Smax.emplace(mx[i],i);
	}
	ll res=numeric_limits<ll>::max();
	//choose Rmin->Rmax->Bmin->Bmax
	Rn=*Smin.begin();
	auto it=Smax.rbegin();
	if(it->second==Rn.second) it--;
	Rx=*it;
	if(mx[Rn.second]<mn[Rx.second]) 
		Bn={mx[Rn.second],Rn.second},		
		Bx={mn[Rx.second],Rx.second};
	else
		Bn={mn[Rx.second],Rx.second},
		Bx={mx[Rn.second],Rn.second};
	//choose Bmin first
	P oldBn=Bn,oldBx=Bx;
	if(Smax.begin()->first<Bn.first) Bn=*Smax.begin();
	for(int i=0;i<n;++i)
		if(i!=Rn.second&&i!=Rx.second&&i!=Bn.second){
			if(mn[i]<Bn.first) Bx.first=max(Bx.first,mx[i]);
			else Bx.first=max(Bx.first,mn[i]);
		}
	res=min(res,1LL*(Rx.first-Rn.first)*(Bx.first-Bn.first));
	//choose Bmax first
	Bn=oldBn,Bx=oldBx;
	if(Smin.rbegin()->first>Bx.first) Bx=*Smin.rbegin();
	for(int i=0;i<n;++i)
		if(i!=Rn.second&&i!=Rx.second&&i!=Bx.second){
			if(mx[i]>Bx.first) Bn.first=min(Bn.first,mn[i]);
			else Bn.first=min(Bn.first,mx[i]);
		}
	res=min(res,1LL*(Rx.first-Rn.first)*(Bx.first-Bn.first));
	//choose Bmin->Rmax->Bmax->Rmin
	Bn=Rn;
	Rn={mx[Bn.second],Bn.second};
	Bx={mn[Rx.second],Rx.second};
	P oldRn=Rn;
	oldBx=Bx;
	//choose Rmin first
	if(Smax.begin()->first<Rn.first) Rn=*Smax.begin();
	for(int i=0;i<n;++i)
		if(i!=Rn.second&&i!=Rx.second&&i!=Bn.second){
			if(mx[i]>=Rn.first) Bx.first=max(Bx.first,mn[i]);
			else Bx.first=max(Bx.first,mx[i]);
		}
	res=min(res,1LL*(Rx.first-Rn.first)*(Bx.first-Bn.first));
	//choose Bmax first
	Rn=oldRn;
	Bx=oldBx;
	if(Smin.rbegin()->first>Bx.first) Bx=*Smin.rbegin();
	for(int i=0;i<n;++i)
		if(i!=Rx.second&&i!=Bn.second&&i!=Bx.second){
			if(mn[i]<=Bx.first) Rn.first=min(Rn.first,mx[i]);
			else Rn.first=min(Rn.first,mn[i]);
		}
	res=min(res,1LL*(Rx.first-Rn.first)*(Bx.first-Bn.first));
//	cerr<<Rx.first<<' '<<Rn.first<<' '<<Bx.first<<' '<<Bn.first<<'\n';
	cout<<res<<'\n';
}


