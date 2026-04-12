#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
#define Mid ((L+R)/2)
#define Left (2*Node)
#define Right (2*Node+1)

using namespace std;

const ll N = 200200;
const ll M = 4 * N;
const ll Inf = 1e18;

ll n;
ll Dp[N];
ll SegTree[M];
ll Lazy[M];
vector <pll> Range[N];

void Merge(ll Node)
{
    SegTree[Node] = min(SegTree[Left],SegTree[Right]);
}

void Push_Lazy(ll Node)
{
    SegTree[Node] += Lazy[Node];

    if(Left < M)    Lazy[Left] += Lazy[Node];
    if(Right < M)   Lazy[Right] += Lazy[Node];

    Lazy[Node] = 0;
}

void Build(ll Node = 1,ll L = 0,ll R = n + 1)
{
    if(L == R)
    {
        SegTree[Node] = Dp[L];
        return ;
    }

    Build(Left,L,Mid);
    Build(Right,Mid+1,R);

    Merge(Node);
}

void Update(ll i,ll j,ll val,ll Node = 1,ll L = 0,ll R = n + 1)
{
    Push_Lazy(Node);

    if(i > R || L > j)  return ;
    if(i <= L && R <= j)
    {
        Lazy[Node] += val;
        Push_Lazy(Node);
        return ;
    }

    Update(i,j,val,Left,L,Mid);
    Update(i,j,val,Right,Mid+1,R);

    Merge(Node);
}

ll Query(ll i,ll j,ll Node = 1,ll L = 0,ll R = n + 1)
{
    Push_Lazy(Node);

    if(i > R || L > j)      return Inf;
    if(i <= L && R <= j)    return SegTree[Node];

    return min(Query(i,j,Left,L,Mid)
             , Query(i,j,Right,Mid+1,R));
}

int main()
{
    ll m;   cin >> n >> m;

    ll Sum = 0;

    while(m--)
    {
        ll l,r,a;   scanf("%lld%lld%lld",&l,&r,&a);

        Sum += a;

        Range[l].push_back({r,a});
    }

    Dp[n+1] = 0;
    Update(n+1,n+1,0);

    for(ll i = n; ~i; --i)
    {
        Dp[i] = Query(i+1,n+1);

        Update(i,i,Dp[i]);

        for(pll p : Range[i])   Update(p.first+1,n+1,p.second);
    }

    ll Ans = Inf;

    for(ll i = 0; i <= n + 1; i++)  Ans = min(Ans,Dp[i]);

    cout << Sum - Ans;
}
