//https://beta.atcoder.jp/contests/arc095/tasks/arc095_a
#include <bits/stdc++.h>
using namespace std;
pair<int,int> v[200001];
int ans[200001] = {};

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v+1,v+1+n);
    int a = v[n/2+1].first;
    int b = v[n/2].first;
    for(int i=1;i<=n;i++)
    {
        int idx = v[i].second;
        if(i <= n/2) ans[idx] = a;
        else ans[idx] = b;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
    return 0;
}
