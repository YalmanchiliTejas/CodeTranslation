#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


int main()
{
    int N;
    int H;
    cin >> N;
    int m = 0;
    int ans = 0;
    for (int i = 0; i < N;i++)
    {
        cin >> H;
        if(m <= H)
        {
            ans++;
        }
        m = max(m, H);
    }
    cout << ans << endl;
    return 0;
}
