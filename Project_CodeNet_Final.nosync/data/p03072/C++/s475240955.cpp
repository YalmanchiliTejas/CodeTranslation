//Edson
#include <iostream>
#include <vector>

using namespace std;

int solve(int N, const vector<int>& hs)
{
    int ans = 0, m = hs[0];

    for (int i = 1; i < N; ++i)
    {
        // Verifica se é possível ver o horizonte a partir deste ponto
        if (hs[i] >= m)
            ++ans;

        // Atualiza a altura a ser comparada
        m = max(m, hs[i]);
    }

    return ans + 1;
}

int main()
{
    int N;
    cin >> N;

    vector<int> hs(N);

    for (int i = 0; i < N; ++i)
        cin >> hs[i];

    cout << solve(N, hs) << '\n';

    return 0;
}