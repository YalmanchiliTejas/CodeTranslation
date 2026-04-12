#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    vector<int> ans(N);

    int now = N / 2, dis = -1;
    for (int i = 0; i < N; i++)
    {
        ans[now] = list[i];
        now += dis;
        dis *= -1;
        if (dis > 0)
            dis++;
        if (dis < 0)
            dis--;
    }
    if (N % 2 == 1)
        reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
}