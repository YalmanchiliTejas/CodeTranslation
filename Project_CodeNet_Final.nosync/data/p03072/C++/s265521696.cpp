#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (auto &i: H) cin >> i;
    int max = H[0];
    int ans = 1;
    for (int i = 1; i < N; i++)
    {
        if (H[i] >= max)
        {
            max = H[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}