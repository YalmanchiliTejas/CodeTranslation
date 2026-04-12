#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int x[200001],y[200001];
int main()
{
    int n;
    scanf("%d",&n);
    int mn=1000000000,mx=1;
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",x+i,y+i);
        if (x[i]>y[i])
            swap(x[i],y[i]);
        mn=min(mn,x[i]);
        mx=max(mx,y[i]);
    }
    if (mn==mx)
    {
        printf("0\n");
        return 0;
    }
    long long ans;
    {
        int mxl=1,mnr=1000000000;
        for (int i=1;i<=n;++i)
        {
            mxl=max(mxl,x[i]);
            mnr=min(mnr,y[i]);
        }
        ans=(long long)(mxl-mn)*(mx-mnr);
    }
    int both=0;
    for (int i=1;i<=n;++i)
        if (x[i]==mn&&y[i]==mx)
            ++both;
    if (both)
    {
        int tmp1=1000000000,tmp2=1;
        for (int i=1;i<=n;++i)
        {
            if (y[i]==mx&&x[i]!=mn)
                tmp1=min(tmp1,x[i]);
            else
                tmp1=min(tmp1,y[i]);
            if (x[i]==mn&&y[i]!=mx)
                tmp2=max(tmp2,y[i]);
            else
                tmp2=max(tmp2,x[i]);
        }
        ans=min(ans,(long long)(mx-mn)*min(mx-tmp1,tmp2-mn));
    }
    else
    {
        vector<pair<int,int>> out;
        int mni=1000000000,mxi=0;
        for (int i=1;i<=n;++i)
        {
            if (x[i]==mn)
            {
                mni=min(mni,y[i]);
                mxi=max(mxi,y[i]);
            }
            else if (y[i]==mx)
            {
                mni=min(mni,x[i]);
                mxi=max(mxi,x[i]);
            }
        }
        for (int i=1;i<=n;++i)
            if (x[i]!=mn&&y[i]!=mx)
            {
                if (y[i]<mni)
                    mni=y[i];
                else if (x[i]>mxi)
                    mxi=x[i];
            }
        for (int i=1;i<=n;++i)
            if (x[i]!=mn&&y[i]!=mx&&x[i]<mni&&y[i]>mxi)
                out.push_back(make_pair(x[i],y[i]));
        sort(out.begin(),out.end());
        int right=mxi;
        for (size_t i=0;i<out.size();++i)
        {
            ans=min(ans,(long long)(mx-mn)*(right-out[i].first));
            right=max(right,out[i].second);
        }
        ans=min(ans,(long long)(mx-mn)*(right-mni));
    }
    printf("%lld\n",ans);
    return 0;
}
