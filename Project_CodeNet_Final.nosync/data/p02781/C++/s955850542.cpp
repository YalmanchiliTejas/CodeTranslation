//正难则反 
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
#define N 200005
#define LL long long
inline int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f*x;
}
char n[105];
int k,len;
LL s[N],ans;
LL ksm(LL a,int b)
{
	LL res=1;
	for(int i=1;i<=b;i++)
		res*=a;
	return res;
}
void Pre() 
{
    s[0]=1;
    for(int i=1;i<=105;i++)
        s[i]=s[i-1]*i;
}
/*LL C(int a,int b) 
{
    if(a<0||b<0) return 1;
    return s[a]/s[b]/s[a-b];
}*/
LL C(LL a,int b)
{
	if(b<0) return 0;
	if(b==0) return 1;
	if(b==1) return a;
	if(b==2) return max(a*(a-1)/2,0ll);
	if(b==3) return max(a*(a-1)*(a-2)/6,0ll);
}
int main()
{
    scanf("%s",n+1);
	k=rd();
    //Pre();
    len=strlen(n+1);
    int t=0;
    for(int i=1;i<=len;i++)
    {//减去大于n的数 
    	int x=n[i]-'0';
    	ans+=(9-x)*C(len-i,k-i+t)*ksm(9,k-i+t);
    	if(!x) t++;
	}
	LL all=C(len,k)*ksm(9,k);//位数有len位的有k个数位恰好不为0的数 
	printf("%lld\n",max(all-ans,0ll));
    return 0;
}
/*#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
#define N 200005
#define LL long long
inline int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f*x;
}
char n[105];
int k,len;
LL s[N],ans;
LL ksm(LL a,int b)
{
	LL res=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
void dfs(int x/*现在到第几位,int y/*已经有y位不为0,LL res,bool f) 
{
	printf("%lld %lld %d\n",res,ans,x); 
	//if(res==-1) printf("%d\n",x);
	if(y>k) return ;
	if(f==1)
	{
		if(y==k) ans+=res;
		return ;
	}
	if(x==len+1)
	{
		if(y==k) ans+=res;
		return ;
	}
	dfs(x+1,y,res,f);//1让这一位为0
	if((n[x]-'0')>1) 
		dfs(x+1,y+1,res*(n[x]-'0'-1)*ksm(9,k-(y+1)),1);//这一位为小于n[x]的数 
	if(n[x]!='0') dfs(x+1,y+1,res,f);//让这一位为n[x] 
	return ;
}
void Pre() 
{
    s[0]=1;
    for(int i=1;i<=N;i++)
        s[i]=s[i-1]*i;
}
LL C(int a,int b) 
{
    if(a<0||b<0) return 1;
    return s[a]/s[b]/s[a-b];
}
int main()
{
    scanf("%s",n+1);
	k=rd();
    Pre();
    len=strlen(n+1);
    int x=n[1]-'0';
    //每个位置都有9个选择 
    if(x!=1) ans=ksm(9,k-1)*C(len-1,k-1)*(x-1);//第1位小于x 可以随便选
    if(len-1>=k) ans+=ksm(9,k)*C(len-1,k);//第1位没有(为0 
	printf("%lld\n",ans);
    dfs(2,1,1,0);//第1位为x 
    printf("%lld\n",ans);
    return 0;
}*/