//ΔAGC033E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
const int MO = 1e9+7;
char ch[N];
int n,m,ans,f[N],s[N];
int main()
{
	int i,x,y,o;
	scanf("%d%d%s",&n,&m,ch+1);
	for(i=1;i<=m;i=i+1)
		if(ch[i]!=ch[1])
			break;
	if(i<=m){
		o=i-1;
		if(o%2==0)
			o++;
		x=1,y=0;
		for(i=i+1;i<=m;i=i+1){
			if(ch[i]==ch[i-1])
				x++;
			else{
				if(y&&x%2==1)
					o=min(o,x);
				y^=1;
				x=1;
			}
		}
	}
	else{
		f[1]=1;
		s[1]=1;
		for(i=2;i<=n;i=i+1){
			f[i]=s[i-2];
			s[i]=(s[i-1]+f[i])%MO;
		}
		x=1;
		for(i=1;i<n;i=i+1)
			x+=(LL)f[i]*(n-i+1)%MO,x%=MO;
		cout<<x;
		return 0;
	}
	if(n&1){
		cout<<0;
		return 0;
	}
	o++;
	o/=2;
	n/=2;
	if(o>n)
		o=n;
	f[1]=1;
	s[1]=1;
	for(i=2;i<=n;i=i+1){
		x=i-o-1;
		if(x<0)
			y=0;
		else
			y=s[x];
		f[i]=(s[i-1]-y+MO)%MO;
		s[i]=(s[i-1]+f[i])%MO;
	}
	x=0;
	for(i=n-o+1;i<=n;i=i+1)
		x+=(LL)f[i]*((n-i+1)*2)%MO,x%=MO;
	cout<<x;
	return 0;
}