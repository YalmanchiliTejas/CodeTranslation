#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

vector<pair<ll,pair<int, int> > >edges;

int p[100004], rnk[100004];

int findp(int a)
{
    if(p[a]==a)return a;
    return p[a] = findp(p[a]);
}
bool connected(int a,int b)
{
    return findp(a)==findp(b);
}
void connect(int a, int b)
{
    int pa = findp(a), pb =findp(b);
    if(rnk[pa]>rnk[pb])p[pb]=pa;
    else if(rnk[pb]>rnk[pa])p[pa]=pb;
    else p[pb]=pa, rnk[pa]++;
}

int main()
{
    for(int i=0;i<100004;i++)p[i]=i;
    int n;
    cin>>n;
    vector< pair<ll,ll>  > X, Y;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        X.push_back({a,i+1});
        Y.push_back({b,i+1});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for(int i=0;i<X.size()-1;i++)
        edges.push_back({X[i+1].first - X[i].first,{X[i].second, X[i+1].second}});
    for(int i=0;i<Y.size()-1;i++)
        edges.push_back({Y[i+1].first - Y[i].first,{Y[i].second, Y[i+1].second}});


    ll ans=0;
    sort(edges.begin(), edges.end());
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i].second.first, b=edges[i].second.second, c=edges[i].first;
        if(!connected(a, b))ans+=c, connect(a, b);
    }
    cout<<ans;
    return 0;
}
/*int n;
    cin>>n;
    ll arr[n], ans=1e18;
    ll sum1 = 0 , sum2 = 0;

    for(int i=0;i<n;i++)
        cin>>arr[i];


    for(int b=-10;b<=10;b++)
    {
        ll cnt=0;
        ll sum1=0, sum2=0;
        for(int i=0;i<n;i++)
            cnt+=abs(arr[i]-(b+i)),
            sum1+=arr[i],
            sum2+=b+i;
        cout<<b<<' ' <<cnt<<' '<<sum1-sum2<<' '<<sum1<<' '<<sum2<<endl;
    }*/
