#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> H(N, 0);
    for (int i = 0; i < N; ++i)
     cin >> H[i];
    
    int ans = 0;
    int wall = 0;
    for (int i = 0; i < N; ++i)
    {
        if (H[i] >= wall)
        {
        ans++;
        wall = H[i];
        }
    }

    cout << ans << endl;
}