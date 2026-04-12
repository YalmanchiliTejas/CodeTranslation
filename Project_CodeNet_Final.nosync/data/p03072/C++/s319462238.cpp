#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, answer = 1;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    int cnt = H[0];

    for (int i = 1; i < N; i++)
    {
        if (H[i] >= cnt)
        {
            cnt = H[i];
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}