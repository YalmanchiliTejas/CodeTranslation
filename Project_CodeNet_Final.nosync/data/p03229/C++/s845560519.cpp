#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<string> g;

int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    vector<ll> c1;
    vector<ll> c2;
    for (int i = 0; i < n / 2; ++i)
    {
        c1.push_back(a[i]);
        c2.push_back(a[n - 1 - i]);
    }
    
    ll r1 = 0;
    ll r2 = 0;
    for (int i = 0; i < c1.size() - 1; ++i)
    {
        r1 += c1[i];
    }
    for (int i = 0; i < c2.size() - 1; ++i)
    {
        r2 += c2[i];
    }
    r1 *= 2ll;
    r2 *= 2ll;
    ll ret = r2 - r1 + c2[c2.size() - 1] - c1[c1.size() - 1];
    if (n % 2)
    {
        cout << max(ret + c2[c2.size() - 1] - a[n / 2], ret + a[n / 2] - c1[c1.size() - 1]) << endl;
    }
    else
    {
        cout << ret << endl;
    }
    
    return 0;
}