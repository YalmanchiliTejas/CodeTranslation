#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int front = a[0];
    int back = a[n - 1];
    int left = 0;
    int right = n - 1;

    ans += abs(back - front);

    while (right - left > 1)
    {
        int fl = abs(front - a[left + 1]);
        int fr = abs(front - a[right - 1]);
        int bl = abs(back - a[left + 1]);
        int br = abs(back - a[right - 1]);

        // front-leftの絶対値が最大である時
        if (fl > fr && fl > bl && fl > br)
        {
            ++left;
            ans += abs(front - a[left]);
            front = a[left];
        }
        // front - rightの絶対値が最大である時
        else if (fr > bl && fr > br)
        {
            --right;
            ans += abs(front - a[right]);
            front = a[right];
        }
        // back - leftの最大値が最大である時
        else if (bl > br)
        {
            ++left;
            ans += abs(back - a[left]);
            back = a[left];
        }
        // back - rightの最大値が最大である時
        else
        {
            --right;
            ans += abs(back - a[right]);
            back = a[right];
        }
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}