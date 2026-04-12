#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  a,b,c,x,y,sum1,sum2,mi,d,p,m,ans[3];
    cin>>a>>b>>c>>x>>y;
    ans[0]=a*x+b*y;

    sum1=(c)*x*2;
    if(x<y)
        mi=y-x;
    else
        mi=0;
    mi*=b;

    ans[1]=sum1+mi;

    sum2=c*y*2;
    if(x>y)
        mi=x-y;
    else
        mi=0;
    mi*=a;
    ans[2]=sum2+mi;

    sort(ans,ans+3);

        cout<<ans[0]<<endl;




    return 0;
}

