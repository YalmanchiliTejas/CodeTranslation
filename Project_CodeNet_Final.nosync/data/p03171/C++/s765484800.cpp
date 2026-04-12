#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define int long long
#define ld long double
#define vi vector<long long>
#define mkp make_pair
#define sz(x) (int)x.size()
#define pi pair<long long, long long>
#define watch(x) cout << (#x) << " is " << (x) << endl; cout.flush()
#define endl '\n'
#define _ << ' '
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, d), min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, d), max(b, c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x


int n, sum=0;
vector<int> v(1000001);

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("A.txt", "r", stdin);
    #endif
    cin >> n;
    int s=0, x, ans=0;
    for(int i=0; i<n; i++)
    {
        cin >> v[s];
        sum += v[s++];
        while(s>=3&&v[s-3]<=v[s-2]&&v[s-2]>=v[s-1])
        {
            v[s-3] = v[s-3] - v[s-2] + v[s-1];
            s -= 2;
        }
    }
    int sgn = 1, i=0, j=s-1;
    while(i<=j)
    {
        if(v[i]>v[j]) ans += sgn * v[i++];
        else ans += sgn * v[j--];
        sgn *= -1;
    }
    cout << ans; //cout << (ans + sum)/2;
    return 0;
}
