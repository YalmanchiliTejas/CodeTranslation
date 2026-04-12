#include <bits/stdc++.h>

using namespace std;

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mkp make_pair
#define trav(x, i) for(auto& i : x)

constexpr int INF =  1000000001;
constexpr int MOD =  1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;


int main() {
    FASTIO;
    int x;
    cin >> x;
    if(x >= 30) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
