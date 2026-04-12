#include <bits/stdc++.h>
using namespace std;

int n,x[200005];
pair<int,int> a1[200005],a[200005];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        a[i]={x[i],i};
        a1[i]={x[i],i};
    }
    sort(a+1,a+1+n);
    int m=a[n/2].first,M=a[n/2+1].first;
    for(int i=1;i<=n;i++)
    {
        a1[a[i].second].second=i;
    }
    /*for(int i=1;i<=n;i++)
        cout<<a1[i].first<<" "<<a1[i].second<<endl;*/
    for(int i=1;i<=n;i++)
    {
        if(a1[i].second<=n/2)
            cout<<M<<endl;
        else if(a1[i].second>=n/2+1)
            cout<<m<<endl;
    }

    return 0;
}
