#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    friend bool operator < (const node &a,const node &b)
    {
        return a.x<b.x;
    }
};
node c[200005];
int x[200005],y[200005];
const int inf=1000000007;
int mins[200005],maxs[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int r_max=-1,b_max=-1;
    int r_min=inf,b_min=inf;
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        if (x[i]>y[i]) swap(x[i],y[i]);
        c[i].x=x[i];
        c[i].y=y[i];
        r_max=max(r_max,x[i]);
        b_max=max(b_max,y[i]);
        r_min=min(r_min,x[i]);
        b_min=min(b_min,y[i]);
    }
    long long ans1=(long long)(r_max-r_min)*(b_max-b_min);
    //B can be chosen randomly now!
    b_min=r_min;
    sort(c,c+n);
    int ans=inf;
    for (i=0;i<n;i++)
    {
        mins[i]=c[i].y;
        maxs[i]=c[i].y;
        if (i>0) mins[i]=min(mins[i-1],c[i].y);
        if (i>0) maxs[i]=max(maxs[i-1],c[i].y);
        if (i!=n-1)
        {
            ans=min(ans,max(maxs[i],c[n-1].x)-min(mins[i],c[i+1].x));
        }
        else
        {
            ans=min(ans,maxs[i]-mins[i]);
        }
    }
    cout<<min((long long)ans*(b_max-b_min),ans1)<<endl;
    return 0;
} 
