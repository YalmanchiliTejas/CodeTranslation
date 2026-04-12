#include <iostream>
#include <vector>

#define INF (1e9)
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);

    int highest = -INF;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
        highest = max(highest, H[i]);
        if (H[i] >= highest)
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}