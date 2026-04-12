#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
#include<memory.h> 
#include<sstream>
#include<time.h>
#include<iomanip>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const int MOD=1000000007;
const long long LMOD=1000000007;
//const long long LMOD=1000000007;
#define Fi first
#define Se second
#define P2 pair
#define Pii pair<int,int>
#define Cb make_pair
#define ll long long
#define Ull unsigned long long
#define Sf scanf
#define Pf printf
#define Pb push_back
#define Psh push
#define Stc stack
#define Vct vector
#define Ret return
#define Sz size
#define Ins insert
#define Que queue
#define Emp empty
#define Fro front
#define Rv reverse
#define Er erase
ll f[105][105][2];
ll h[105];
ll pw(ll a,ll b)
{
	if(b==1)return a;
	if(b==0)return 1;
	ll t=pw(a,b/2);
	if(b&1)return t*t*a%LMOD;
	return t*t%LMOD;
}
ll K(ll l,ll r,ll bt)
{
	//cout<<l<<" "<<r<<" "<<bt<<endl;
	ll mn=BIGER;
	for(ll i=l;i<r;i++)
	{
		//mn=min(mn,h[i]);
		if(h[i]!=h[i+1])
		{
			for(ll i=l;i<=r;i++)mn=min(mn,h[i]);
			ll g=0;
			for(ll i=l;i<=r;i++)if(h[i]==mn)g++;
			ll lq=l,rq=l,res[2];
			res[0]=2;
			res[1]=1;
			while(lq<=r)
			{
				//cout<<">"<<lq<<" "<<rq<<" "<<l<<" "<<r<<" "<<mn<<endl;
				while(lq<=r&&h[lq]==mn)lq++,rq++;
				while(rq<=r&&h[rq]>mn)rq++;rq--;
				if(lq<=r)
				{
					K(lq,rq,mn+1);
					res[0]=res[0]*f[lq][rq][0]%MOD;
					res[1]=res[1]*(f[lq][rq][0]*2+f[lq][rq][1])%MOD;
				}
				rq++;
				lq=rq;
			}
			//cout<<"!"<<res[1]<<" "<<res[0]<<"!"<<endl;
			res[1]=res[1]*pw(2,g)%MOD;
			res[1]=(res[1]+MOD-res[0])%MOD;
			res[0]=res[0]*pw(2,mn-bt)%MOD;
			f[l][r][0]=res[0];
			f[l][r][1]=res[1];
			return 0;
		}
	}
	//cout<<"!";
	f[l][r][1]=(pw(2,r-l+1)+MOD-2)%MOD;
	f[l][r][0]=pw(2,h[l]-bt+1)%MOD;
	//cout<<"!";
	return 0;
}
int main()
{
	ll n;
	Sf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		Sf("%lld",&h[i]);
	}
	K(1,n,1);
	cout<<(f[1][n][0]+f[1][n][1])%MOD<<endl;
	/*
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cout<<f[i][j][0]<<","<<f[i][j][1]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}