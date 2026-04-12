#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H.at(i);
    }

    int res = 0;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            res++;
            max = H.at(i);
        }
        else
        {
            if (max < H.at(i))
            {
                max = H.at(i);
            }
            if (max <= H.at(i) && H.at(i - 1) <= H.at(i))
            {
                res++;
            }
        }
    }
    cout << res << endl;
}