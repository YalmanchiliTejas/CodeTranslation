#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
lli ver(vector<lli> a)
{
    lli n = a.size();
    lli cnt = 0;
    while (true) {
        bool flag = false;
        rep(i, n)
        {
            lli temp = 0;
            if (a[i] >= n) {
                temp += a[i] / n;
                a[i] = a[i] % n;
                flag = true;
                cnt += temp;
            }
            rep(j, n) if (i != j) a[j] += temp;
        }
        if (!flag)
            return cnt;
    }
}
bool check(lli k, vector<lli> a)
{
    lli n = a.size();

    double sum = 0;
    rep(i, n)
    {
        //sum += max(0LL, ((a[i] + k - n + 1) % (1 + n) == 0 ? (double)((a[i] + k - n + 1)) / (1 + n) : (double)(a[i] + k - n + 1) / (1 + n) + 1));
        sum += max(0.0, (((double)a[i] + k - n + 1) / (1 + n)));
    }
    cout << "#" << sum << endl;
    return sum <= k;
}
lli ver2(vector<lli> a)
{
    lli n = a.size();
    lli up = 1e18;
    lli low = 0;
    //cout << check(3, a) << endl;
    while (up - low > 1) {
        lli mid = (up + low) / 2;
        if (check(mid, a)) {
            up = mid;
        } else {
            low = mid;
        }
    }
    return up;
}
int main()
{
    int n;
    cin >> n;
    vector<lli> h(n);
    bool flag = false;
    rep(i, n)
    {
        cin >> h[i];
        if (h[i] >= n)
            flag = true;
    }
    if (flag)
        cout << ver(h) << endl;
    else
        cout << 0 << endl;
}
void solve()
{
    lli k;
    cin >> k;
    lli h = 1e16;
    lli n = (k / h) + 2;
    if (n > 50) {
        n = 50;
    }

    vector<lli> a(n, n + k / n);
    rep(i, k % n) a[i] -= i;
    rep(i, n - k % n) a[k % n + i] -= k % n + 1;

    cout << n << endl;
    rep(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    //cout << ver(a) << endl;
}
