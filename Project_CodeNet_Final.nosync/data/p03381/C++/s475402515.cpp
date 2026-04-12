#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
vi v;
int n;
 
tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> t;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int,int> mp;
    while(cin >> n)
    {
        v = vi(n); t.clear(); mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            t.insert({v[i], mp[v[i]]++});
        }
	mp.clear();
	for(int i = 0; i < n; i++)
	{
		t.erase({v[i], mp[v[i]]});
		cout << (*t.find_by_order((n-1)/2)).first << '\n'; 
		t.insert({v[i], mp[v[i]]++});
	}
    }
    return 0;
}