#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans=0;
    for(int b=k+1;b<=n;b++)
    {
        int c1=n/b*(b-k);
        int c2=max(0,n%b-k+1);
        ans+=c1+c2;
        if(k==0)
            ans--;
    }
    printf("%lld\n",ans);
	return 0;
}

