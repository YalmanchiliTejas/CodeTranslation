#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> a(N);
    for (int &t: a)
        cin>>t;

    long long inv = 10000000000000LL;
    vector<vector<long long>> T(N, vector<long long>(N, inv));

    function<long long(int, int)> f = [&](int p, int q) -> long long
    {
        if (p>q)
            return 0;
        if (T[p][q] != inv)
            return T[p][q];
        return T[p][q] = max(
            a[p] - f(p+1, q),
            a[q] - f(p, q-1));
    };
    cout<<f(0, N-1)<<endl;
}
