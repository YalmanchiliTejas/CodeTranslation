#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;
int inf = 2e9, mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n,sum = 0, res = 0; cin >> n;
    vi arr(n);
    for(auto &v:arr) cin >> v;
    for(;*max_element(all(arr)) >= n;){
        sum = 0;
        for(auto &v:arr) sum += v/n;
        res += sum;
        for(auto &v:arr) v = sum - v/n + v%n;
    }
    cout << res << endl;
    return 0;
}
