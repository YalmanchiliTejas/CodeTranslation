#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdlib.h>
 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
 
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e8+6;//maxn*maxs
const int maxs=1e8+10;
const int mod=998244353;
int f[maxn];
ll pr[maxn];
int main()
{
	ll n,x,m;
	cin>>n>>x>>m;
	for(int i=0;i<m;i++)
		f[i]=-1;
	ll ans=0;
	int a=0;
	while(n){
		n--;
		f[x]=a++;
		pr[x]=ans;
		ans+=x;

		x=x*x%m;
		if(f[x]>=0){
			int b=a-f[x];
			ans+=(ans-pr[x])*(n/b);
			n%=b;
		}
	}
	cout<<ans<<endl; 	
    system("pause");
    return 0;
}
	

