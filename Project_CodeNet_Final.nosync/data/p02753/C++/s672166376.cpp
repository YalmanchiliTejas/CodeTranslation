/* Author: Rennan Rocha
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    for(char c : s) {
        if(c == 'A') a++;
        else b++;
    }

    if(a == 2 && b == 1) cout << "Yes\n";
    else if(b == 2 && a == 1) cout << "Yes\n";
    else cout << "No\n";
}
