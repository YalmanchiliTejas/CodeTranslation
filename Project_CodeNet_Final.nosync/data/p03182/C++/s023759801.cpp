#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int nax = 2e5+10;
const ll INF =1e18+10;
struct S
{
    ll small,lazy;

    void merge(const S& a,const S& b)
    {
        small=min(a.small,b.small);
    }

    void add (ll x)
    {
        small+=x;
        lazy+=x;
    }
};
vector <S> tree;

void rec(int id,int low, int high,int q_low,int q_high,int type,ll& x)
{
    if (high < q_low || low > q_high)
        return;

    if (high<=q_high && low>=q_low)
    {
        if (type==1)
            tree[id].add(x);
        if (type==2)
            x = min (x,tree[id].small);
        return;
    }

    for (int b: {2 * id,2*id + 1} )
        tree[b].add(tree[id].lazy);
    tree[id].lazy=0;

    int mid = (low+high)/2;
    rec(2 * id,low,mid,q_low,q_high,type,x);
    rec(2 * id + 1,mid + 1,high,q_low,q_high,type,x);

    tree[id].merge(tree[2*id],tree[2*id+1]);
}

vector <pair< int,int> > intervals[nax];
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;;

    long long sum=0;
    for (int i=0;i<m;i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        intervals[b].emplace_back(a,x);
        sum+=x;
    }

    int base = 1;
    while (base<=n+1)
        base*=2;

    tree.resize(2 * base,{INF,0});

    ll whatever = 0-INF;
    rec(1,0,base-1,0,0,1,whatever);

    ll ans=0;
    for (int i=1;i<=n+1;i++)
    {
        for (pair <int,int> p:intervals[i-1])
        {
            whatever=p.second;
            rec(1,0,base-1,0,p.first-1,1,whatever);
        }

        ll best=INF;
        rec(1,0,base-1,0,base-1,2,best);

        if (i==n+1)
            ans=best;

        whatever=best-INF;
        rec(1,0,base-1,i,i,1,whatever);
    }

    cout << sum-ans;
}

