#include <bits/stdc++.h>
using namespace std;
#define LIM 300010
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1
#define ll long long
#define OUTSIDE en<l || st>r
#define INSIDE st>=l && en<=r
#define INF 1<<19

struct info
{
    int mn,lazy;
    info() {}
    info(int a,int b){mn = a;lazy = b;}
};

info tree[4*LIM+5];
set<int>L,R;
char str[LIM+5];
int n,sum[LIM+5];

void relax(int n)
{
    tree[n+n].mn+=tree[n].lazy;
    tree[n+n].lazy+=tree[n].lazy;
    tree[n+n+1].mn+=tree[n].lazy;
    tree[n+n+1].lazy+=tree[n].lazy;
    tree[n].lazy = 0;
}

void build(int st,int en,int n)
{
    if(st==en){tree[n] = info(sum[st],0);return;}
    build(left);
    build(right);
    tree[n].mn = min(tree[n+n].mn,tree[n+n+1].mn);
}

void update(int st,int en,int n,int l,int r,int x)
{
    if(INSIDE){tree[n].mn+=x;tree[n].lazy+=x;return;}
    if(OUTSIDE)return;
    relax(n);
    update(left,l,r,x);
    update(right,l,r,x);
    tree[n].mn = min(tree[n+n].mn,tree[n+n+1].mn);
}

int query(int st,int en,int n,int l,int r)
{
    if(OUTSIDE)return INF;
    if(INSIDE)return tree[n].mn;
    relax(n);
    return min(query(left,l,r),query(right,l,r));
}

void flip(int pos)
{
    if(str[pos]=='(')
    {
        str[pos]=')';
        L.erase(pos);
        R.insert(pos);
        update(0,n-1,1,pos,n-1,-2);
    }
    else
    {
        str[pos]='(';
        R.erase(pos);
        L.insert(pos);
        update(0,n-1,1,pos,n-1,2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q,pos;
    cin >> n >> q >> str;
    for(int i=0; i<n; i++)
    {
        if(!i)sum[i] = (str[i]=='('?1:-1);
        else sum[i]=sum[i-1]+(str[i]=='('?1:-1);
        if(str[i]=='(') L.insert(i);
        else R.insert(i);
    }
    build(0,n-1,1);
    for(int i=0; i<q; i++)
    {
        cin >> pos;--pos;
        if(str[pos]=='(')
        {
            flip(pos);
            int ans = *(R.begin());
            cout << ans+1 << "\n";
            flip(ans);
        }
        else
        {
            flip(pos);
            int l,r,mid;
            l = 0;
            r = n;
            while(l<r)
            {
                mid=(l+r)/2;
                if(query(0,n-1,1,mid,pos)>=2)r = mid;
                else l = mid+1;
            }
            int res = *(L.lower_bound(l));
            flip(res);
            cout << res+1 << "\n";
        }
    }

    return 0;
}

