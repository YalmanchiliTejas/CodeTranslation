#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<13> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> vvi;

//set iterator can be increamnted and decreamnted
void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    fast();
    //    freopen("input.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
    ll n, x, m;
    cin >> n >> x >> m;
    ll total = 0;
    ll arr[2 * m + 1];
    clr(arr, 0);
    arr[0] = x;
    int i = 1, s;
    bool b = 0;
    map<ll, int> freq;
    for (i = 1; i < m; ++i) {

        arr[i] = binpow(arr[i - 1], 2, m);
        if (freq[arr[i]]) {
            s = freq[arr[i]];
            break;
        }
        freq[arr[i]] = i;
    }
    if (n <= i) {
        ll t = 0;
        for (int j = 0; j < n; ++j) {
            t += arr[j];
        }
        cout << t;
    } else {

        ll t = 0;
        for (int j = 0; j < i; ++j) {
            t += arr[j];
        }
        ll now = 0;
        for (int j = s; j < i; ++j) {
            now += arr[j];
        }
        n -= i;

        if(i-s>0) {
            ll r = n / (i - s);
            t += (r) * now;


            for (int k = s; k < s + n % (i - s); ++k) {
                t += arr[k];
            }
        }
        cout << t;
    }

}