#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N);
    set<long long> s;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        s.insert(A[i]);
    }
    map<long long, int> m;
    int idx = 0;
    for (auto x : s)
    {
        m[x] = idx;
        idx++;
    }

    for (int i = 0; i < N; i++)
    {
        A[i] = m[A[i]];
    }
    // for (long long a : A)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;

    vector<int> q(1, 1000000);
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= q.back())
        {
            q.push_back(A[i]);
            continue;
        }
        int l = 0;
        int r = q.size() - 1;
        while (r - l > 1)
        {
            int c = (l + r) / 2;
            if (A[i] > q[c])
            {
                r = c;
            }
            else
            {
                l = c;
            }
        }
        q[r] = A[i];
    }
    cout << q.size() - 1 << endl;
    // for (int x : q)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
}
