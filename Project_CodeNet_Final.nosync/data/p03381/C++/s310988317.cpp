#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main()
{
    int n,x,mid;
    cin>>n;
    vector<pair<int,int> >v;
    int ans[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.pb(mp(x,i));
    }
    sort(v.begin(),v.end());
    mid=n/2-1;
    for(int i=mid+1;i<n;i++)
    {
        ans[v[i].second]=v[mid].first;
    }
    for(int i=0;i<=mid;i++)
    {
        ans[v[i].second]=v[mid+1].first;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
}
