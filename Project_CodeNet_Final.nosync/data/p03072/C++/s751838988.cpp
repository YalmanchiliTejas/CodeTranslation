#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, max, ans = 1;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    max = list[0];
    for (int i = 1; i < N; i++)
    {
        if (max <= list[i])
        {
            ans++;
            max = list[i];
        }
    }
    cout << ans;
}