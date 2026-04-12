#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll m;
void add(ll &a, ll b)
{
    a = (a + b);
}
int main()
{
    ll n, x;
    cin >> n >> x >> m;
    set<int> s;
    vector<int> v(1e5+10);
    s.insert(x);
    v[0] = x;
    bool flag = false;
    int start = 0;
    int end = 0;
    for(int i = 1; i <= m; i++)
    {
        x = (x * x) % m;
        v[i] = x;

        if(s.find(x) != s.end())
        {
            end = i-1;
            flag = true;
            for(int j = 0; j <= i; j++)
            {
                if(v[j] == x)
                {
                    start = j;
                    break;
                }
            }
        }
        if(flag) break;
        s.insert(x);
    }
    ll ans = 0;
    for(int i = 0; i < start; i++) add(ans, v[i]);
    ll num = 0;
    for(int i = start; i <= end; i++) add(num, v[i]);
    ll dis = end - start + 1;
    ll wid = (n - start) / dis;
    add(ans, wid * num);
    for(int i = start; i < start + (n-start) % dis; i++)
    {
        add(ans, v[i]);
    }
    cout << ans << endl;
}
