#include <bits/stdc++.h>
using namespace std;
long long f[101],tmp[101];
char k[10001];
int main()
{
	int l,i,d,a=0,b,j;
	long long ans=0;
    scanf("%s",k);
    scanf("%d",&d);
    l=strlen(k);
    for(i=0;i<l;i++)
		a+=k[i]-'0';
    f[0]=1;
    a%=d;
    if(a==0)
		ans++;
	l--;
    while(l>=0)
	{
        if(k[l]!='0')
		{
            b=k[l]-'0';
            a-=b;
            while(a<0)
                a+=d;
            if(a)
                j=d-a;
            else
                j=0;
            for(i=0;i<b;i++)
			{
                ans+=f[j--];
                if(j<0)
					j+=d;
            }
            ans%=1000000007;
        }
        tmp[0]=0;
        j=d-1;
        for(i=0;i<9;i++)
		{
            tmp[0]+=f[j--];
            if(j<0)
				j+=d;
            tmp[0]%=1000000007;
        }
        for(i=1;i<d;i++)
        {
			j++;
			tmp[i]=tmp[i-1]+f[i-1]-f[j%d];
		}
        for(i=0;i<d;i++)
		{
            f[i]=f[i]+tmp[i];
            f[i]%=1000000007;
            f[i]+=1000000007;
            f[i]%=1000000007;
        }
        l--;
    }
    ans--;
    if(ans<0)
		ans+=1000000007;
    printf("%d",ans);
    return 0;
}