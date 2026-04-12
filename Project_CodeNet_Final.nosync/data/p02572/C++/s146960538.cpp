#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> que;
    int64_t tsum = 0;
    int con;
    int64_t s = 0;
    int64_t mod = 1000000007;
    for (int i = 0; i < n; i++)
    {
        cin >> con;
        que.push(con);
        tsum += con;
    }
    for (int i = 0; i < n - 1; i++)
    {
        tsum -= que.front();
        s += ((que.front() % mod) * (tsum % mod)) % mod;
        que.pop();
    }

    cout << s % mod << endl;
}