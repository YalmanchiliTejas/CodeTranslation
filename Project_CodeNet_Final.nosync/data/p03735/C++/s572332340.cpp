#include<bits/stdc++.h>
#define x first
#define y second
#define N 200005
using namespace std;
pair<int,int> p[N];
vector<pair<int,int> > v;
int n;
int main(){
	scanf("%d",&n);
	int mx=0,mn=0;p[0].y=1e9+1;
	int mxx=-1,mxy=-1,mnx=1e9+1,mny=1e9+1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		if(p[i].x<p[i].y) swap(p[i].x,p[i].y);
		if(p[i].x>=p[mx].x) mx=i;
		if(p[i].y<=p[mn].y) mn=i;
		mxx=max(mxx,p[i].x);mnx=min(mnx,p[i].x);
		mxy=max(mxy,p[i].y);mny=min(mny,p[i].y);
	}
	long long ans=(mxy-mny)*1LL*(mxx-mnx);
	if(mx!=mn&&n>2){
		vector<pair<int,int> > v;
		for(int i=1;i<=n;i++)
			if(i!=mx&&i!=mn)
				v.push_back(p[i]);
		int nx=max(p[mx].y,p[mn].x);
		sort(v.begin(),v.end());
		int nowmn=min(min(p[mx].y,p[mn].x),v[0].x);
		for(int i=v.size()-1;i>=0;i--){
			if(v[i].x<=nx) break;
			ans=min(ans,(v[i].x-nowmn)*1LL*(p[mx].x-p[mn].y));
			nowmn=min(nowmn,v[i].y);
			nx=max(nx,v[i].y);
		}
		ans=min(ans,(nx-nowmn)*1LL*(p[mx].x-p[mn].y));
	}
	cout<<ans<<endl;
	return 0;
} 