#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main()
{
    llint N, X, M;

    cin >> N >> X >> M;

    if (N == 1)
    {
        cout << X << endl;

        return 0;
    }
    // ループするまで
    vector<bool> sumi(M, false);

    llint sum = 0;
    llint A;

    bool loop = false;
    llint loop_start = -1;

    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            A = X;
        }
        else
        {
            A = (A * A) % M;
        }
        sum += A;
        loop_start = A;

        if (sumi[A] == false)
        {
            sumi[A] = true;
        }
        else
        {
            loop = true;

            break;
        }
    }
    if (loop = false)
    {
        cout << sum << endl;

        return 0;
    }
    // ループの開始まで
    sum = 0;

    llint i = 1;

    while (true)
    {
        if (i == 1)
        {
            A = X;
        }
        else
        {
            A = (A * A) % M;
        }
        sum += A;
        i++;

        if (A == loop_start)
        {
            break;
        }
    }
    // ループの長さ
    llint count = 0;
    llint sum_part = 0;

    while (true)
    {
        A = (A * A) % M;
        sum_part += A;
        count++;
        i++;

        if (A == loop_start)
        {
            break;
        }
    }

    i -= count;
    sum += ((N + 1 - i) / count) * sum_part;
    i += ((N + 1 - i) / count) * count;
    // ループの終了から
    for (; i <= N; i++)
    {
        A = (A * A) % M;
        sum += A;
    }
    cout << sum << endl;
}