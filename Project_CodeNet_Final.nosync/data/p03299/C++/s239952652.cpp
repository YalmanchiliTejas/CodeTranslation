//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=105,MOD=1e9+7;
inline int pow_mod(int x,int i){int y=1;while(i){if(i&1)y=(ll)y*x%MOD;x=(ll)x*x%MOD;i>>=1;}return y;}
int n,h[MAXN];
vector<int>vec,w[MAXN];
int solve1(int l,int r,int k,int low){
	//cout<<"dp1 "<<l<<" "<<r<<" "<<k<<endl;
	int mx=0,mn=2e9;
	for(int i=l;i<=r;++i)mx=max(mx,h[i]),mn=min(mn,h[i]);
	if(mn>k)return solve1(l,r,mn,low);
	if(mx==k&&mx==mn)return pow_mod(2,vec[k]-low);
	
	int ans=1,st=lob(w[k].begin(),w[k].end(),l)-w[k].begin(),ed=lob(w[k].begin(),w[k].end(),r)-w[k].begin();
	ed=min(ed,(int)w[k].size()-1);
	if(w[k][ed]>r)ed--;
	int lst=l;
	for(int i=st;i<=ed;++i){
		assert(w[k][i]>=l&&w[k][i]<=r);
		if(lst<=w[k][i]-1)ans=(ll)ans*solve1(lst,w[k][i]-1,k+1,vec[k])%MOD;
		lst=w[k][i]+1;
	}
	if(lst<=r)ans=(ll)ans*solve1(lst,r,k+1,vec[k])%MOD;
	ans=(ll)ans*pow_mod(2,vec[k]-low)%MOD;
	return ans;
}
int solve2(int l,int r,int k,int low){
	//cout<<l<<" "<<r<<" "<<k<<endl;
	int mx=0,mn=2e9;
	for(int i=l;i<=r;++i)mx=max(mx,h[i]),mn=min(mn,h[i]);
	if(mn>k)return solve2(l,r,mn,low);
	if(mx==k&&mx==mn)return (pow_mod(2,r-l+1)-2+pow_mod(2,vec[k]-low))%MOD;
	
	int st=lob(w[k].begin(),w[k].end(),l)-w[k].begin(),ed=lob(w[k].begin(),w[k].end(),r)-w[k].begin();
	ed=min(ed,(int)w[k].size()-1);
	if(w[k][ed]>r)ed--;
	vector<int>dp1,dp2;
	int lst=l,t=0;
	for(int i=st;i<=ed;++i){
		assert(w[k][i]>=l&&w[k][i]<=r);
		t++;
		if(lst<=w[k][i]-1)dp1.pb(solve1(lst,w[k][i]-1,k+1,vec[k])),dp2.pb(solve2(lst,w[k][i]-1,k+1,vec[k]));
		lst=w[k][i]+1;
	}
	if(lst<=r)dp1.pb(solve1(lst,r,k+1,vec[k])),dp2.pb(solve2(lst,r,k+1,vec[k]));
	int ans1=1,ans2=1;
	for(int i=0;i<(int)dp1.size();++i)ans1=(ll)ans1*(dp1[i]+dp2[i])%MOD,ans2=(ll)ans2*dp1[i]%MOD;
	ans1=(ll)ans1*pow_mod(2,t)%MOD;
	ans2=(ll)ans2*(pow_mod(2,vec[k]-low)-2)%MOD;
	return (ans1+ans2)%MOD;
}
int main() {
	n=read();
	for(int i=1;i<=n;++i)h[i]=read(),vec.pb(h[i]);
	vec.pb(0);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n;++i)h[i]=lob(vec.begin(),vec.end(),h[i])-vec.begin(),w[h[i]].pb(i);
	cout<<solve2(1,n,1,0)<<endl;
	return 0;
}