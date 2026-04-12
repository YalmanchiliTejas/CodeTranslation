#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
    int a,b,c,x,y;
    int ans=0,cnta=0,cntb=0;;
    cin>>a>>b>>c>>x>>y;
    float ma,mb;
    ma=(a)/(float)(a+b)*c;
    mb=(b)/(float)(a+b)*c;
    if((2*c)<(a+b))
        {
            if(x<y)
            {
                int cc=cnta;
                cnta+=(x-cc);
                cntb+=(x-cc);
                ans+=x*2*c;
            }
           else
           {
                int cc=cntb;
                cnta+=(x-cc);
                cntb+=(x-cc);
                ans+=y*2*c;
           }
        }
        else
        {
             cout<<x*a+y*b;
             return 0;
        }

        if(x>y){
        int cc=min(2*c,a);
        ans+=(cc*(x-y));
    }
    else{
        int cc=min(2*c,b);
        ans+=(cc*(y-x));
    }
    cout<<ans;
    return 0;
}
