#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    vector<int> H;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        H.push_back(temp);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (H[i] < H[j])
            {
                flag = false;
            }
        }
        cnt += flag ? 1 : 0;
    }
    cout << cnt;
    return 0;
}