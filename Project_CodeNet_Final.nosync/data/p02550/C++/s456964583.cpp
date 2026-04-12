#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxm = 1e5 + 5;

int n, x, m, used[maxm];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> m;
    deque<int> cycle, tail;
    cycle.push_back(x);
    for(int i = 0; i < m; i++)
    {
        int cur = cycle.back();
        cur *= cur;
        cur %= m;
        if(used[cur])   // At max m distinct remainders, so will occur before that
        {
            while(cycle.front() != cur)
            {
                tail.push_back(cycle.front());
                cycle.pop_front();
            }
            break;
        }
        cycle.push_back(cur);
        used[cur] = 1;
    }
    int ans = 0;
    for(int i = 0; i < tail.size() && n > 0; i++)
    {
        ans += tail[i];
        n--;
    }
    int times = n / cycle.size(), extra = n % cycle.size();
    for(int i = 0; i < cycle.size(); i++)
    {
        ans += cycle[i] * times;
        if(i < extra)
            ans += cycle[i];
    }
    cout << ans << "\n";
    return 0;
}