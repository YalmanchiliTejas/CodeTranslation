#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int calc(int tot,int k)
{
    if(k>tot) return 0;
    k--;tot--;
    int num=1,fac=1;
    for(int i=0;i<k;i++)
        num*=(tot-i);
    for(int i=1;i<=k;i++)
        fac*=i;
    int type=num/fac,res=1,each=1;
    for(int i=0;i<k;i++)
        each*=9;
    res=type*each;
    return res;
}
signed main()
{
    string n;
    cin>>n;
    int len=(int)n.length(),k;
    n="_"+n;
    scanf("%lld",&k);
    if(k>len)
    {
        puts("0");
        return 0;
    }
    if(k==1)
    {
        int ans=0;
        ans+=(len-1)*9;
        ans+=(n[1]-'0');
        printf("%lld\n",ans);
    }
    else if(k==2)
    {
        int ans=0;
        for(int i=1;i<len;i++)
            ans+=9*(i-1)*9;
        ans+=(n[1]-'0'-1)*(len-1)*9;
        for(int i=2;i<=len;i++)
            if(n[i]!='0')
            {
                ans+=(n[i]-'0');
                ans+=(len-i)*9;
                break;
            }
        printf("%lld\n",ans);
    }
    else if(k==3)
    {
        int ans=0;
        for(int i=1;i<len;i++)
            ans+=9*((i-1)*(i-2)/2)*81;
        ans+=(n[1]-'0'-1)*((len-1)*(len-2)/2)*81;
        for(int i=2;i<=len;i++)
            if(n[i]!='0')
            {
                int left=len-i;
                ans+=(left*(left-1)/2)*81;
                ans+=(n[i]-'0'-1)*left*9;
                for(int j=i+1;j<=len;j++)
                    if(n[j]!='0')
                    {
                        ans+=(n[j]-'0');
                        ans+=(len-j)*9;
                        break;
                    }
                break;
            }
        printf("%lld\n",ans);
    }
    return 0;
}
