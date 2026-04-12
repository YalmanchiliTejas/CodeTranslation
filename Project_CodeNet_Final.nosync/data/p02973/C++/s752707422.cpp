/**
*     ________   ________   ___        ________          ________   ___        ________       ___    ___  _______    ________
*    |\   ____\ |\   __  \ |\  \      |\   __  \        |\   __  \ |\  \      |\   __  \     |\  \  /  /||\  ___ \  |\   __  \
*    \ \  \___|_\ \  \|\  \\ \  \     \ \  \|\  \       \ \  \|\  \\ \  \     \ \  \|\  \    \ \  \/  / /\ \   __/| \ \  \|\  \
*     \ \_____  \\ \  \\\  \\ \  \     \ \  \\\  \       \ \   ____\\ \  \     \ \   __  \    \ \    / /  \ \  \_|/__\ \   _  _\
*      \|____|\  \\ \  \\\  \\ \  \____ \ \  \\\  \       \ \  \___| \ \  \____ \ \  \ \  \    \/  /  /    \ \  \_|\ \\ \  \\  \|
*        ____\_\  \\ \_______\\ \_______\\ \_______\       \ \__\     \ \_______\\ \__\ \__\ __/  / /       \ \_______\\ \__\\ _\
*       |\_________\\|_______| \|_______| \|_______|        \|__|      \|_______| \|__|\|__||\___/ /         \|_______| \|__|\|__|
*       \|_________|                                                                        \|___|/
*/

#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
typedef vector<vector<ll>> mat;

const int N = 1e5 + 5;
int n , a[N] , out;
vector<int> se;

int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        auto x = upper_bound(se.begin() , se.end() , a[i]);
        if(x == se.end()) se.push_back(a[i]);
        else *x = a[i];
    }
    cout << se.size();

    return 0;
}
