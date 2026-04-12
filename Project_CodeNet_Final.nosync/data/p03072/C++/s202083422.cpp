#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
//#include <bits/stdc++.h>
using namespace std;
/*inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}*/
typedef long long ll;
const int inf=0x3f3f3f3f;
map<ll,ll>mp;
ll a[200000+5];
ll p[40];
int main()
{
    int n,ans=0,f;
    while(cin>>n)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            f=1;
            for(int j=i;j>=1;j--)
                if(a[j]>a[i])
                {
                    f=0;
                    break;
                }
            if(f==1)
                ans++;
        }
       cout<<ans<<endl;
    }

    return 0;
}