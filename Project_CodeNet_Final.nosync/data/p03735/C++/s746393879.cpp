#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int N;
ll x[200000],y[200000];
int main(){
	cin>>N;
	int amn=0,amx=0;
	rep(i,N){
		cin>>x[i]>>y[i];
		if(x[i]>y[i]) swap(x[i],y[i]);
		if(x[amn]>x[i]) amn = i;
		if(y[amx]<y[i]) amx = i;
	}
	if(N==1){
		puts("0");
		return 0;
	}
	ll ans = 2e18;
	if(amn!=amx){	//rr
		using P = pair<ll,ll>;
		priority_queue<P,vector<P>,greater<P>> que;
		vector<bool> canmove(N,true);

		ll mx = 0;
		ll res = 2e18;
		rep(i,N){
			if(i!=amn){
				que.push(P(x[i],i));
				chmax(mx,x[i]);
			}else{
				que.push(P(y[i],i));
				chmax(mx,y[i]);
			}
		}
		canmove[amn] = canmove[amx] = false;

		while(!que.empty()){
			P p = que.top();
			que.pop();
			ll v = p.fs;
			int i = p.sc;
			chmin(res,mx-v);
			chmax(mx,y[i]);

			if(!canmove[i]) break;

			que.push(P(y[i],i));
			canmove[i] = 0;
		}
		chmin(ans,res*(y[amx]-x[amn]));
	}
	{	//(max - rmin)*(bmax - min)
		ll rmx = -2e18, rmn = 2e18, bmx = -2e18, bmn = 2e18;
		rep(i,N){
			chmax(rmx,x[i]);
			chmin(rmn,x[i]);
			chmax(bmx,y[i]);
			chmin(bmn,y[i]);
		}
		ll tmp = (rmx-rmn)*(bmx-bmn);
		chmin(ans,tmp);
	}
	cout<<ans<<endl;

}
