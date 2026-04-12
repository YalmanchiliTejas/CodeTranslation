#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    int K;
    cin >> N >> K;
    vector<int> n(N.size());
    for (int i = 0; i < N.size(); i++)
    {
        n[i] = N[i] - '0';
    }
    long long ans = 0;
    if (K == 1)
    {
        ans += n.front();
        ans += 9 * (n.size() - 1);
    }
    if (K == 2)
    {
        ans += (n.front() - 1) * 9 * (n.size() - 1);
        for (long long i = 1; i < n.size(); i++)
        {
            if (n[i] > 0)
            {
                ans += n[i];
                ans += 9 * (n.size() - (i + 1));
                break;
            }
        }
        ans += 9 * 9 * ((n.size() - 1) * (n.size() - 2) / 2);
    }
    if (K == 3)
    {
        ans += (n.front() - 1) * 9 * 9 * ((n.size() - 1) * (n.size() - 2) / 2);
        for (long long i = 1; i < n.size(); i++)
        {
            if (n[i] > 0)
            {
                ans += (n[i] - 1) * 9 * (n.size() - (i + 1));
                ans += 9 * 9 * ((n.size() - (i + 1)) * (n.size() - (i + 2)) / 2);
                for (long long j = i + 1; j < n.size(); j++)
                {
                    if (n[j] > 0)
                    {
                        ans += n[j];
                        ans += 9 * (n.size() - (j + 1));
                        break;
                    }
                }
                break;
            }
        }
        ans += 9 * 9 * 9 * ((n.size() - 1) * (n.size() - 2) * (n.size() - 3) / 6);
    }
    cout << ans << endl;
}
