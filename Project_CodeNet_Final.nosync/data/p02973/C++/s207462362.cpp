#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;
int n , a[N] , seg[4*N];
set<int> st;
set<int> ::iterator it;

void update(int node , int st , int en , int idx , int val)
{
    if (st==en)
    {
        seg[node] = val;
    }
    else
    {
        int mid = (st+en)/2;
        if (st <= idx && idx <= mid) update(2*node , st , mid , idx , val);
        else update(2*node+1 , mid+1 , en , idx , val);
        seg[node] = max(seg[2*node] , seg[2*node+1]);
    }
}

int query(int node , int st , int en , int l , int r)
{
    if (r<st || l>en) return -1e9;

    if (l<=st && en <= r)
        return seg[node];

    int mid = (st+en)/2;
    return max(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}

int BS(int idx)
{
    int l=idx+1 , h=n , mid , ans=1e9;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (query(1,1,n,idx+1,mid) > a[idx])
        {
            ans = min(ans , mid);
            h = mid-1;
        }
        else l=mid+1;
    }
    if (ans == 1e9) return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        update(1,1,n,i,a[i]);
        st.insert(i);
    }

    int ans=0;
    while(st.size())
    {
        ans++;
        int idx = *st.begin();
        while(idx != -1)
        {
            update(1,1,n,idx,(int)-1000000000);
            st.erase(idx);
            idx = BS(idx);
        }
    }

    cout << ans << '\n';

    return 0;
}