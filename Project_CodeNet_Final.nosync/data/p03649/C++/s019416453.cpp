#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
ll a[maxn];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    ll res = 0;
    while(true){
        bool add = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(a[i] >= n)add = 1;
            for(int j = 1 ; j <= n ; ++j){
                if(j != i)a[j] += a[i] / n;
            }
            res += a[i] / n;
            a[i] %= n;
        }
        if(add == 0)break;
    }
    cout << res;
}
