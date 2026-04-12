#include <bits/stdc++.h>
using namespace std;

void solve(int64_t N, int64_t X, int M)
{
    vector<int> occured(M, -1);
    occured.at(X) = 0;
    vector<int64_t> A(M);
    A.at(0) = X;
    int idx_start = N, len_loop = 0;
    int i = 1;
    while (i < N)
    {
        int Ai = (A.at(i - 1) * A.at(i - 1)) % M;
        if (occured.at(Ai) >= 0)
        {
            idx_start = occured.at(Ai);
            len_loop = i - idx_start;
            break;
        }
        occured.at(Ai) = i;
        A.at(i) = Ai;
        i++;
    }

    int64_t ans = 0;
    for (int i = 0; i < idx_start; i++)
    {
        ans += A.at(i);
    }
    if (len_loop > 0)
    {
        int64_t sum_loop = 0;
        for (int i = 0; i < len_loop; i++)
        {
            sum_loop += A.at(idx_start + i);
        }
        int64_t cnt_loop = (N - idx_start) / len_loop;
        ans += sum_loop * cnt_loop;
        int res_loop = (N - idx_start) % len_loop;
        for (int i = 0; i < res_loop; i++)
        {
            ans += A.at(idx_start + i);
        }
    }
    cout << ans << endl;
}

int main()
{
    int64_t N;
    cin >> N;
    int64_t X;
    cin >> X;
    int M;
    cin >> M;
    solve(N, X, M);
    return 0;
}
