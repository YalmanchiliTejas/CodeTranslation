#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

template <typename T>
void print(vector<T> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << (i == n - 1 ? "\n" : " ");
    }
}

int n, m = 0, ans;

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (m <= v[i])
            ans++;
        m = max(m, v[i]);
    }
    cout << ans << endl;
}