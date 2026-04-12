#include <bits/stdc++.h>
#define ll long long
#define N 200005
#define Inf 1e18L + 5
using namespace std;
int n , m;
vector < pair < int , ll > > Interval[N];

ll st[4*N] , lazy[4*N];
void push(int p ,int l ,int r)
{
    if(lazy[p])
    {
        st[p] += lazy[p];
        if(l != r)
        for(auto i : {2*p , 2*p+1})
            lazy[i] += lazy[p];
        lazy[p] = 0;
    }
}
void update(int a, int b , ll val , int l = 0 ,int r = n+1 , int p = 1)
{
    push(p,l,r);
    if(b < l || r < a)return;
    if(a <= l && r <= b)
    {
        lazy[p] += val;
        push(p,l,r);
        return;
    }
    int mid = (l+r)>>1;
    update(a,b,val,l,mid,2*p);
    update(a,b,val,mid+1,r,2*p+1);
    st[p] = min(st[2*p],st[2*p+1]);
}
ll q(int a, int b, int l = 0 , int r = n+1 , int p = 1)
{
    push(p,l,r);
    if(b < l || r < a) return Inf;
    if(a <= l && r <= b)return st[p];
    int mid = (l+r)>>1;
    return min(q(a,b,l,mid,2*p) , q(a,b,mid+1,r,2*p+1));
}
int main()
{
    ll sum_of_cost = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; i++)
    {
        int l , r , x;
        scanf("%d%d%d",&l,&r,&x);
        Interval[r].push_back({l,x});
        sum_of_cost += x;
    }

    ll ans = 0;
    update(0,n,0);
    for(int i = 1 ; i <= n + 1; i++)
    {
        for(auto range : Interval[i-1])
            update(0,range.first - 1, range.second);

        ll res = q(0,i-1);
        if(i == n+1)
            ans = res;
        update(i,i,res);
    }
    printf("%lld\n", sum_of_cost - ans);
    return 0;
}
