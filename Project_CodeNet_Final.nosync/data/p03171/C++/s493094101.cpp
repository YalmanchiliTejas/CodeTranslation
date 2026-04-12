/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#include<algorithm>
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define vi vector<ll>
#define pii pair<ll,ll>
#define bc __builtin_popcountll
#define vvi vector<vi> 
#define vpii vector<pair<ll,ll>>
#define mll unordered_map<ll,ll>
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define fo(i,a,b) for(i=a;i<=b;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<=n;i++)
#define fb(i,n) for(ll i=n-1;i>=0;i--)
#define fb1(i,n) for(ll i=n;i>0;i--)
#define endd cout<<'\n';
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define clr(x) memset(x, -1.00, sizeof(x))
#define sortall(x) sort(all(x))
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define CASES  ll t;cin>>t;while(t--)
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
//*X.find_by_order()-->returns an iterator to the k-th largest element (counting from zero)
//X.order_of_key()-->the number of items in a set that are strictly smaller than our item.
struct cmp
{
	bool operator() (ll a,ll b){
		return (a>b);
	}
};
ll ceil(const ll &a, const ll &b)
{
    if(a%b == 0)
        return a/b;
    return a/b +1;
}
ll mod=1000000007;
const ll N=3005;
ll dp[N][N][2];
ll a[N];
ll go(ll i,ll j,ll k)
{
    if(i>j)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    ll res;
    if(k==0)
    {
        res=max(a[i]+go(i+1,j,1),a[j]+go(i,j-1,1));
    }
    else
    {
        res=min(-a[i]+go(i+1,j,0),-a[j]+go(i,j-1,0));
    }
    return dp[i][j][k]=res;
}
int main()
{
fast;
    ll n;
    cin>>n;
    f(i,n)
        cin>>a[i];
    clr(dp);
    cout<<go(0,n-1,0);   
    return 0;
}
