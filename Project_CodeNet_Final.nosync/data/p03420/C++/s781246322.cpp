#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,k;
	ll ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		ll a=(int)((n+1)/i);
		ans+=a*max(0LL,i-k);
		ll tn=(n+1)-a*i;
//		cout<<i<<' '<<ans<<endl;
		ans+=max(0LL,tn-k);
		if(k==0) ans--;
	}
	cout<<ans<<endl;
	return 0;
}