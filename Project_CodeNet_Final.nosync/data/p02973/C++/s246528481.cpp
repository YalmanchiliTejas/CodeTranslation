#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int INF = 1e18;
const int M = 1e9 + 7;
//__int128

const int maxn = 3e5;
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    std::vector<int> a(n);
    static int b[maxn];
    for(int i = 0; i < n; ++i) {
    	cin >> a[i];
    	a[i] = -a[i];
    }
    int cnt = -1;
    for(int i = 0; i < n; ++i) {
    	int x = upper_bound(b, b + cnt + 1, a[i]) - b;
    	b[x] = a[i];
    	cnt = max(cnt, x);
    }
    cout << cnt + 1 << endl;
    return 0;
}