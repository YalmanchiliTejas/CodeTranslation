#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back
#define mp make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<30)
#define LLINF (1<<60)
#define MOD 1000000007
#define rep(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a[100005] = {}, c[100005] = {};
    ll ansa = 0, ansb = 0, ans;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a+n);
    if (n % 2 == 0) {
        int t = n / 2;
        c[0] = a[t - 1];
        c[n - 1] = a[t];
        for (int i = 1; i < n - 1; i++) {
            if (i % 2 == 1)c[i] = a[i/2];
            else c[i] = a[t + i / 2];
        }
        for (int i = 0; i < n-1; i++) {
            ansa += abs(c[i] - c[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (i % 2 == 1)c[i] = a[t + (i+1) / 2];
            else c[i] = a[(i-1) / 2];
        }
        for (int i = 0; i < n - 1; i++) {
            ansb += abs(c[i] - c[i + 1]);
        }
        ans = max(ansa, ansb);
    }
    else {
        int t = n / 2;
        c[0] = a[t];
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) c[i] = a[i / 2];
            else c[i] = a[n - i / 2];
        }
        for (int i = 0; i < n - 1; i++) {
            ansa += abs(c[i] - c[i + 1]);
        }
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) c[i] = a[n - (i+1) / 2];
            else c[i] = a[i / 2 - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            ansb += abs(c[i] - c[i + 1]);
        }
        ans = max(ansa, ansb);
    }
    cout << ans << endl;
    return 0;
}
