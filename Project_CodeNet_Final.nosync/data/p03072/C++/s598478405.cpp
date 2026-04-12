#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp2;
        cin >> tmp2;
        if (tmp <= tmp2)
        {
            ans++;
            tmp = tmp2;
        }
    }
    cout << ans << endl;
    return 0;
}