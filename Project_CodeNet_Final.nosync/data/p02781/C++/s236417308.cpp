#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(!x){putchar('0');return;}
	int top=0;
	while(x)stack[++top]=x%10,x/=10;
	while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
char ss[110];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf("%s",ss+1);int len=strlen(ss+1);
    int n=read();
    if(n==1)pr2(ss[1]-'0'+(len-1)*9);
    else if(n==2)
    {
    	int ans=0;
    	for(int i=1;i<=len;i++)
    	{
    		for(int j=i+1;j<=len;j++)
    		{
    			for(int k1=1;k1<=9;k1++)
    			{
    				for(int k2=1;k2<=9;k2++)
    				{
    					bool bk=true;
    					for(int k=1;k<=len;k++)
    					{
    						int uf=0;
    						if(k==i)uf=k1;
							if(k==j)uf=k2;
							if(ss[k]-'0'>uf){break;}
    						if(ss[k]-'0'<uf){bk=false;break;}
    					}
    					if(bk==true)ans++;
    				}
    			}
    		}
    	}
    	pr2(ans);
    }
    else
    {
    	int ans=0;
    	for(int i=2;i<=len;i++)
    	{
    		for(int j=i+1;j<=len;j++)
    		{
    			if(j<len)ans+=9*9*9*(i-1);
    			else ans+=(ss[1]-'0'-1)*9*9*(i-1);
    		}
    	}
    	for(int i=2;i<=len;i++)
    	{
    		for(int j=i+1;j<=len;j++)
    		{
    			for(int k1=1;k1<=9;k1++)
    			{
    				for(int k2=1;k2<=9;k2++)
    				{
    					bool bk=true;
    					for(int k=2;k<=len;k++)
    					{
    						int uf=0;
    						if(k==i)uf=k1;
							if(k==j)uf=k2;
							if(ss[k]-'0'>uf){break;}
    						if(ss[k]-'0'<uf){bk=false;break;}
    					}
    					if(bk==true)ans++;
    				}
    			}
    		}
    	}
 		pr2(ans);
    }
    return 0;
}