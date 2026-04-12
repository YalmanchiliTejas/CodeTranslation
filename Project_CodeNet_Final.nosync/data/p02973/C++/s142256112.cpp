#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int main()
{
    int n;
    cin >> n;
    vi mx;
    int mnmx = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);

        bool flg = true;
        if (mnmx < a)
        {
            for (size_t j = 0; j < mx.size(); j++)
            {
                if (mx[j] < a)
                {
                    mx[j] = a;
                    flg = false;
                    break;
                }
            }
        }
        if (flg)
        {
            mx.push_back(a);
            mnmx = a;
        }
    }

    cout << mx.size() << endl;

    return 0;
}
