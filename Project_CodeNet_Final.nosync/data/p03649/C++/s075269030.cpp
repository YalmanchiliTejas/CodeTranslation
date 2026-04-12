#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int N;
vector<lint> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (auto &v : a) cin >> v;
    sort(a.begin(), a.end());

    vector<lint> b(N, 0);
    for (int i=1; i<N; i++) b[i] = (a[i] - a[0]) / (N+1);
    lint res = accumulate(b.begin(), b.end(), 0LL);

    for (int i=0; i<N; i++) a[i] = a[i] - N * b[i] + (res - b[i]);
    sort(a.begin(), a.end());
    // for (auto v : a) cout << v << " ";
    // cout << endl;
    if (a[0] > N)
    {
        lint dif = a[0]-N;
        res += dif * N;
        for (auto &v : a) v -= dif;
    }
    lint border = N;
    // cout << res << endl;
    // for (auto v : a) cout << v << " ";
    while (a.back() >= border)
    {
        a.back() -= (N+1);
        sort(a.begin(), a.end());
        border--;
        res++;
    }
    cout << res << endl;
}