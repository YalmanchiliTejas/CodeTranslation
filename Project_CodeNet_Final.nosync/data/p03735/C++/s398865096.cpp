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
const int maxn = 2e5 + 5;
ii a[maxn];
int n;
multiset<int> s , b;
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
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second)swap(a[i].first ,a[i].second);
        s.insert(a[i].first);
        b.insert(a[i].second);
    }
    sort(a + 1 , a + n + 1);
    ll res = 1e18;
    for(int i = 1 ; i <= n ; ++i){
        res = min(res , (ll)(*s.rbegin() - *s.begin()) * (*b.rbegin() - *b.begin()));
        s.erase(s.find(a[i].first));s.insert(a[i].second);
        b.erase(b.find(a[i].second));b.insert(a[i].first);
    }
    cout << res;
}
