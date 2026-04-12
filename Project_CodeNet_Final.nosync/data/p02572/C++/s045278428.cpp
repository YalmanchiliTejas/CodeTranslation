#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<u_int64_t> a(n);

    for (auto &e: a) cin >> e;

    u_int64_t tmp = 0;
    u_int64_t sum = 0;

    for (int i = n-1; i >= 1; --i) {
        tmp = (tmp + a[i]) % (1000000007);
        sum = (sum + tmp*a[i-1]) % (1000000007);
    }

    cout << sum;

    return 0;
}
