#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    long long res = 0;
    for (int b=K+1; b<=N; b++)
    {
        res += N/b*(b-K) + max((N%b)-max(K, 1)+1, 0);
    }
    cout << res << endl;
}