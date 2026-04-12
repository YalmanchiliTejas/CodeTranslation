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
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<=n;i++)
#define fb(i,n) for(ll i=n-1;i>=0;i--)
#define fb1(i,n) for(ll i=n;i>0;i--)
#define endd cout<<'\n';
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define pii pair<ll,ll>
#define CASES  ll t;cin>>t;while(t--)
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
//*X.find_by_order()
//X.order_of_key()
ll mod=1000000007;
const ll N=100005;
int main()
{
fast;
    ll n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}