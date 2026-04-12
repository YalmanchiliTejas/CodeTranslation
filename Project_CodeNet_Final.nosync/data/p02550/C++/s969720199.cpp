#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ff               first
#define ss               second
#define pb               push_back
#define all(x)           (x).begin(), (x).end()
#define mem0(x)          memset(x, 0, sizeof (x))
#define mem1(x)          memset(x, -1, sizeof (x))

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<vii> vvii;
typedef vector <ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

ll memo[100010];
ll pos[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T=1, n;
    mem1(memo);
    while (T--){
        ll x, m, sum=0;
        cin >> n >> x >> m;
        ll i = 0;
        mem1(pos);
        for (i; i < n; ++i) {
            if (pos[x] != -1) break;
            sum += x;
            memo[i] = sum;
            pos[x] = i;
            x = x*x%m;
        }
        ll left = n-i;
        sum += (sum - (pos[x] == 0 ? 0: memo[pos[x]-1]))*(left/(i-pos[x]));

        left %= (i-pos[x]);
        for (i=0; i < left; ++i) {
            sum += x;
            memo[x] = sum;
            x = x*x%m;
        }
        cout << sum << "\n";
    }
}