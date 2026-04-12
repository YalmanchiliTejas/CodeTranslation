#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    deque <long long> q;

    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        q.push_back(x);

        while(q.size() > 2 && (q.back() <= q[q.size() - 2] && q[q.size() - 2] >= q[q.size() - 3]))
        {
            long long a = q.back() - q[q.size() - 2] + q[q.size() - 3];
            q.pop_back();
            q.pop_back();
            q.pop_back();
            q.push_back(a);
        }
    }

    long long p = 0;

    int i = 1;
    while(!q.empty())
    {
        if(q.front() >= q.back())
        {
            p += i * q.front();
            q.pop_front();
        }else
        {
            p += i * q.back();
            q.pop_back();
        }
        i = -i;
    }

    cout << p << '\n';

    return 0;
}

