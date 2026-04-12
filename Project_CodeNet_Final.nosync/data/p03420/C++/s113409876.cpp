#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long int n, k;
    cin >> n >> k;
    long long int count = 0;
    if(k == 0)
    {
        cout << n * n << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i <= k) continue;
        long long int pre = n / i;
        count += pre * (i - k);
        long long int rest = n % i;
        if(rest == 0) continue;
        if(rest - k + 1 >= 0) count += rest - k + 1;
    }
    cout << count << endl;
    return 0;
}
