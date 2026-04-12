#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

long long f(int N, long long X, vector<long long>&a, vector<long long>&p)
{
    if (N == 0) {
        return 1;
    }
    if (X == 1) {
        return 0;
    } else if (X <= 1 + a[N - 1]) {
        return f(N - 1, X - 1, a, p);
    } else if (X == 2 + a[N - 1]) {
        return p[N - 1] + 1;
    } else if (X <= 2 + 2 * a[N - 1]) {
        return p[N - 1] + 1 + f(N - 1, X - 1 - a[N - 1] - 1, a, p);
    } else {
        return 2 * p[N - 1] + 1;
    }

}

int main()
{
    int N;
    long long X;
    cin >> N >> X;

    vector<long long> a;
    vector<long long> p;

    a.push_back(1);
    p.push_back(1);

    for (int i = 1; i <= N; i++) {
        a.push_back(2 * a[i - 1] + 3);
        p.push_back(2 * p[i - 1] + 1);
    }

    cout << f(N, X, a, p) << endl;

    return 0;
}
