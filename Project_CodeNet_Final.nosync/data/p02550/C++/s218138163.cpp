/*************************************************************************
	> File Name: 4.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/9/19 20:39:53
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define LL long long
using namespace std;
LL read(){
	char x=getchar(); LL u=0,fg=0;
	while(!isdigit(x)){ if(x=='-') fg=1; x=getchar(); }
	while(isdigit(x)){ u=(u<<3)+(u<<1)+(x^48); x=getchar(); }
	return fg?-u:u;
}
const int maxx=1e6+10;
LL a[maxx],c[maxx],n,x,m,cnt=0,sum=0,ans=0,vis[maxx];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	n=read(); x=read(); m=read();
	a[++cnt]=x;
	vis[x]=1;
	while(1){
		a[cnt+1]=a[cnt]*a[cnt]%m;
		if(vis[a[cnt+1]]){
			int j=0;
//			cout<<vis[a[cnt+1]]<<endl;
			for(int i=1;i<=cnt && n>0;++i)
				if(i>=vis[a[cnt+1]]) c[++j]=a[i],sum+=a[i];
				else ans+=a[i],--n;
			
			cnt=j;
			break;
		}
		else{
			vis[a[cnt+1]]=cnt+1;
			++cnt;
		}
	}
	if(cnt){
		ans+=sum*(n/cnt);
		for(int i=1;i<=n%cnt;++i) ans+=c[i];
	}
	printf("%lld\n",ans);


		
	return 0;
}
