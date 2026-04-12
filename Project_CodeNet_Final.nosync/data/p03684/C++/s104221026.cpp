#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
ll n,x,y,tmp,ans;

int par[100005] , sz[100005];

int findPar(int node)
{
    if (par[node]==node) return node;
    return par[node] = findPar(par[node]);
}

void mergeCom(int node , int node2)
{
    int led = findPar(node) , led2 = findPar(node2);

    if (sz[led] > sz[led2])
    {
        par[led2]=led , sz[led] += sz[led2];
    }
    else
    {
        par[led]=led2 , sz[led2] += sz[led];
    }
}

int main()
{
    cin >> n;
    pair < pair<ll,ll> , ll> arr[n+1] , arr2[n+1];
    vector <pair<ll , pair<ll,ll> > > vec;

    for (int i=1; i<=n; i++)
    {
        cin >> x >> y;
        arr[i].f.f=x , arr[i].f.s=y , arr[i].s=i;
        arr2[i].f.f=y , arr2[i].f.s=x , arr2[i].s=i;
        par[i]=i , sz[i]=1;
    }
    sort(arr+1,arr+n+1) , sort(arr2+1,arr2+n+1);
    for (int i=1; i<n; i++)
    {
        tmp = min(abs(arr[i+1].f.f-arr[i].f.f) , abs(arr[i+1].f.s-arr[i].f.s));
        vec.push_back({tmp , {arr[i+1].s , arr[i].s}});

        tmp = min(abs(arr2[i+1].f.f-arr2[i].f.f) , abs(arr2[i+1].f.s-arr2[i].f.s));
        vec.push_back({tmp , {arr2[i+1].s , arr2[i].s}});
    }

    sort(vec.begin() , vec.end());
    tmp = n-1;
    for (int i=0; i<vec.size(); i++)
    {
        if (!tmp) break;
        x = vec[i].s.f , y = vec[i].s.s;
        if (findPar(x)==findPar(y)) continue;
        ans += vec[i].f , tmp--;
        mergeCom(vec[i].s.f , vec[i].s.s);
    }
    cout << ans << "\n";

    return 0;
}
