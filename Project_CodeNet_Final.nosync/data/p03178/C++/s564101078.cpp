//  DO NOT USE:  A   N (segtree)

#include<bits/stdc++.h>
using namespace std;

//														MACROS
#define ll long long
#define pii pair<ll,ll>
#define f(a,b,c) for(ll a=b;a<c;a++)
#define read(t) ll t; cin>>t;
#define readarr(arr,n) ll arr[n]; f(i,0,n) cin>>arr[i];
#define deb(x)  cout<<x<<"         KAMEHAMEHA"<<endl;

//														OBJECTS
struct obj
{
    ll x,y;
};

//														USEFUL FUNCTIONS
ll powm(ll , ll ) ;

//          											SEGMENT TREE(!N)

const int N=3e0+5;
ll tree[4*N+1];
ll A[N];
ll lazy[4*N+1]={0};

void build(ll,ll,ll);
void update(ll,ll,ll,ll,ll);
ll query(ll,ll,ll,ll,ll);
void updateRange(ll,ll,ll,ll,ll,ll);
ll queryRange(ll,ll,ll,ll,ll);

//														GLOBAL VARS
ll INF =LLONG_MAX;
const ll M= 1000000007;
ll dp[100005][100]={0};

// 														MAIN
int main()
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    string s;
    cin>>s;
    read(d)
    dp[0][0]=1;
    f(i,1,100005)//digit ke liye he bitch
    {
        // pehle matrix set kar le
        f(j,0,10)
        {
            f(k,0,d)
            {
                dp[i][(k+j)%d]+=dp[i-1][k];
                dp[i][(k+j)%d]%=M;
            }
        }
    }
    // f(i,0,d) cout<<dp[1][i]<<" ";
    // cout<<endl;
    ll ans=0;
    ll curr=0;
    f(i,0,s.length())
    {
        // deb(ans)
        if(i==s.length()-1)
        f(j,0,(int)(s[i]-'0')+1)
        {
            ll temp=curr+j;
            temp%=d;
            temp=d-temp;
            temp%=d;
            ans+=dp[s.length()-1-i][temp];
            ans%=M;
        }

        else
        {
            f(j,0,(int)(s[i]-'0'))
        {
            ll temp=curr+j;
            temp%=d;
            temp=d-temp;
            temp%=d;
            ans+=dp[s.length()-1-i][temp];
            ans%=M;
        }
        }
        
        curr+=(int)(s[i]-'0');
    }
    ans--;
  if(ans==-1) ans=M-1;
cout<<ans%M<<endl;
  

}










//													FUNCTIONS DECLARATIONS
ll powm(ll a, ll b) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // llernal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // llernal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
