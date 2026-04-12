// Vivek Rai
// Blazer_007

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define ppi			pair<ll,pii>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define bit(x, y)   (((x)>>(y))&1)
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
using namespace __gnu_pbds;

typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int> > minHeap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(index) -> value at given index or Kth smallest element in set
// order_of_key(X) -> number of elements strictly less than X
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

template <typename T>
istream &operator>>(istream &in, vector<T> &arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cin >> arr[i];
    return in;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return os;
}

void solution()
{
	ll n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    ll ans = 0;
    ll sum = arr[n-1] % hell;
    rloop(i,n-2,0)
    {
        ans += ( (arr[i] % hell) * (sum % hell) ) % hell;
        ans %= hell;
        sum = (sum + arr[i] % hell) % hell;
    }
    cout << ans << endl;
}

signed main()
{
    fastio

    ll t = 1;
    // cin >> t;
    loop(i, 1, t + 1)
    {
        //cout<<"Case #"<<i<<": ";
        solution();
    }
}


	