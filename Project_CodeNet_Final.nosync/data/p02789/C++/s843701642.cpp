#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

using pi = pair<int, int>;

typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>Order_Set;

Order_Set X;

const int mxn = 2e5+100;
const int Mod = 1e9+7;

int arr[mxn], qs[mxn];
int bitOn[55];
map<int,int>Mp, cnt, op;
vector<int>Pi, Ans;
vector<int>G[mxn];
set<int>seet[mxn];

int dx[] = {+1, -1, +1, +1, -1, -1};
int dy[] = {+0, +0, -1, +1, -1, +1};

int visit[3][100005];
int n, k;

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    (n == k) ? puts("Yes") : puts("No");

    return 0;
}



