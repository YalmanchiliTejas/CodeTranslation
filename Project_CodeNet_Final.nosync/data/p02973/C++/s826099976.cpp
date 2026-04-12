#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define lpsbd(i, s, b, d) for(size_t i = s; i < b; i+=d)
#define lpsb(i, s, b) for(size_t i = s; i < b; i++)
#define lpn(i, n) for(size_t i = 0; i < n; i++)
#define fa(i, x) for(auto &i: x)
#define vcd(t, n, d) vector<t>(n, d)
#define vc(t, n) vector<t>(n)

using namespace std;
using ull = unsigned long long;

const ull MOD = 1000000007;

int main(void)
{
    int N;
    cin>> N;
    auto A = vc(int, N);
    fa(i, A) cin >> i;
    int M = 0;
    vector<int> ans = {-1, 1000000001};
    int l, r, c;
    for (int i = 0; i < N; i++)
    {
        l = 0;
        r = ans.size() - 1;
        while(r - l > 1)
        {
            c = (l + r) / 2;
            if (ans[c] < A[i]) l = c;
            else r = c;
        }
        if (l) ans[l] = A[i];
        else ans.insert(ans.begin() + 1, A[i]);
    }
    cout << ans.size() - 2 << endl;
    return 0;
}