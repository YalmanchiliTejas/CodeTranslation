#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;
const ll mod = 1e9 + 7;

int main()
{
    int N; cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (H[i] >= max)
        {
            max = H[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}