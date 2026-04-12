#include <bits/stdc++.h>
using namespace std;
int a[200001];
vector<int> v;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    int mid1,mid2;
    mid1 = v[n/2-1];
    mid2 = v[n/2];
    for(int i=0;i<n;i++)
    {
        if(a[i]<=mid1)cout<<mid2<<endl;
        else cout<<mid1<<endl;
    }
}
