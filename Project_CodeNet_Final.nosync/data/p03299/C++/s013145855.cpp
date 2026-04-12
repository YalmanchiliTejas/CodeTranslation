#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<lint,lint> pl;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
int h[110];
lint dp[110][110][110][2];
lint mo=1000000007,m2=(mo+1)/2;
vector<int> de;
lint zyo(lint x,lint y){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
pl cal(int l,int r,int d){
	int mi=114;
	REP(i,l,r) mi=min(mi,h[i]);
	vector<int> v;v.pb(l-1);
	REP(i,l,r){
		if(h[i]==mi) v.pb(i);
	}
	v.pb(r);
	lint r0=1,r1=1;
	if(v.size()==r-l+2){
		r0*=2;r1*=zyo(2,r-l);r1%=mo;
		r1-=r0;r1%=mo;r1+=mo;r1%=mo;
	}
	else{
		vector<pl> p;
		rep(i,(int)v.size()-1){
			if(v[i+1]>v[i]+1) p.pb(cal(v[i]+1,v[i+1],mi));
		}
		rep(i,p.size()){
			r0*=p[i].fi;r0%=mo;
			r1*=(p[i].fi*2+p[i].se);r1%=mo;
		}
		r0*=2;r0%=mo;
		r1*=zyo(2,v.size()-2);r1%=mo;
		r1-=r0;r1%=mo;r1+=mo;r1%=mo;
	}
	//cout<<l<<' '<<r<<' '<<d<<' '<<r0<<' '<<r1<<endl;
	dp[l][r][d][0]=r0*zyo(2,de[mi]-de[d]-1);dp[l][r][d][0]%=mo;
	dp[l][r][d][1]=r1;
	return mp(dp[l][r][d][0],dp[l][r][d][1]);
}
int main()
{
	int n;lint ba=1,out=0;
	cin>>n;
	rep(i,n){
		cin>>h[i];//de.pb(h[i]);
	}
	if(n==1){
		cout<<zyo(2,h[0])<<endl;return 0;
	}
	if(h[0]>h[1]){
		ba*=zyo(2,h[0]-h[1]);h[0]=h[1];ba%=mo;
	}
	if(h[n-1]>h[n-2]){
		ba*=zyo(2,h[n-1]-h[n-2]);h[n-1]=h[n-2];ba%=mo;
	}
	REP(i,1,n-1){
		int t=max(h[i-1],h[i+1]);
		if(h[i]>t){
			ba*=zyo(2,h[i]-t);h[i]=t;ba%=mo;
		}
	}
	//cout<<ba<<endl;
	//rep(i,n) cout<<h[i]<<' ';cout<<endl;
	rep(i,n) de.pb(h[i]);
	de.pb(0);sort(All(de));de.erase(unique(All(de)));
	rep(i,n) h[i]=lower_bound(All(de),h[i])-de.begin();
	memset(dp,-1,sizeof(dp));
	cal(0,n,0);
	out=(dp[0][n][0][0]+dp[0][n][0][1])*ba;
	cout<<out%mo<<endl;
}
