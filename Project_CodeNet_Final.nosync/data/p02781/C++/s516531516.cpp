#include <bits/stdc++.h>

using namespace std;

const int N=1e6+3;

const double eps=0.000000001;

#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;

const int dx[]={1,-1,0,0},
		  dy[]={0,0,1,-1};

const int inf=1e9,mod=1e9+7;

int n,m,a[N],b[N],k,q,u,v,x,y,tc,c,l,r,ans;

char s[N];

void IO(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
}

ll dp[105][5][2];

ll solve(int idx,int nz,bool ls){
	if (idx>=n){
		return nz==k;
	}
	ll &r=dp[idx][nz][ls];
	if (r!=-1)
		return r;
	r=0;
	for(int i=0;i<10;i++){
		x= s[idx]-'0';
		if ((!ls && i>x) || (nz>=k && i))
			break;
		r+=solve(idx+1,nz+(i!=0),ls|(i<x));
	}
	return r;
}

int main(){
	//IO();
	memset(dp,-1,sizeof dp);
	scanf("%s",s);
	scanf("%d",&k);
	n=strlen(s);
	printf("%lld\n",solve(0,0,0));
}
