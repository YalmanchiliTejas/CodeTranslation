#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9
#define f first
#define s second

typedef long long ll;

using namespace std;

const int N = 1e5;
int a[N+5];
int a1[N+5];

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll ans = 0, ans1 = 0;

    cin >> n;

    int arr[n];
    pair <int, int> p[n];

    for (int i = 0; i < n; i++) {

        cin >> arr[i];

        if (i == 0) p[i].first = 1;
        else if (i == n-1) {
            if (i%2) p[i].first = -1;
            else p[i].first = 1;
        } else if (i%2) p[i].first = -2;
        else p[i].first = 2;

        p[i].second = i;
    }

    sort(p, p+n);
    sort(arr, arr+n);

    for (int i = n-1; i >= 0; i--) a[p[i].second] = arr[i];
    for (int i = 0; i < n; i++) a1[p[i].second] = arr[n-1-i];

    for (int i = 0; i < n-1; i++) ans+=abs(a[i+1]-a[i]), ans1+=abs(a1[i+1]-a1[i]);

    cout << max(ans, ans1);

    return 0;
}
