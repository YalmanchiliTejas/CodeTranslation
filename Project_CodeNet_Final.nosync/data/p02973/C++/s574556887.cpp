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
    }

    vector<long long> q(1, 10000000000);
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
}
