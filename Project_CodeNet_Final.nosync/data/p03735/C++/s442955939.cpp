#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define vi vector<int>
#define MAX_N 200005
#define i197 1000000007

using namespace std;


typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,P1> P2;
const int inf=1000000000;
P1 xy[MAX_N]={};

int main() {
	int n;
	ll x1,y1;
	cin>>n;
	rep(i,n){
		cin>>x1>>y1;
		if(x1>y1)swap(x1,y1);
		xy[i]=P1(x1,y1);
	}
	ll Rmax=0,Rmin=i197,Bmax=0,Bmin=i197;
	rep(i,n){
		if(xy[i].second>Rmax){
			Rmax=xy[i].second;
			Bmax=xy[i].first;
		}
		if(xy[i].first<Bmin){
			Bmin=xy[i].first;
			Rmin=xy[i].second;
		}
	}

	rep(i,n){
		if(xy[i].first>Bmax)Bmax=xy[i].first;
		if(xy[i].second<Rmin)Rmin=xy[i].second;
	}
	ll t=(Rmax-Rmin)*(Bmax-Bmin);

//	cout<<t<<endl;
	Rmax=0,Rmin=i197,Bmax=0,Bmin=i197;
	//RMax Rmin
	rep(i,n){
		if(xy[i].second>Rmax){
			Rmax=xy[i].second;
		}
		if(xy[i].first<Rmin){
			Rmin=xy[i].first;
		}
	}
	sort(xy,xy+n);
	Bmax=xy[n-1].first,Bmin=xy[0].first;
	ll Bmin2=Bmax,Bmax2=Bmax;
	ll Bmm=Bmax-Bmin;
//	cout<<Bmax<<" "<<Bmin<<endl;
	rep(i,n-1){
		ll k=xy[i].second;
		Bmin2=min(Bmin2,k);
		Bmax2=max(Bmax2,k);
		Bmm=min(Bmm,max(Bmax2,Bmax)-min(Bmin2,xy[i+1].first));
//		cout<<Bmm<<endl;
	}
	Bmm=min(Bmm,max(Bmax2,xy[n-1].second)-min(Bmin2,xy[n-1].second));

//	cout<<Bmax<<" "<<Bmin<<endl;

	t=min(t,(Rmax-Rmin)*Bmm);


	cout<<t<<endl;
	return 0;
}
