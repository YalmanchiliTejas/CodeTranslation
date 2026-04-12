#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum, result = 0;
    cin >> sum;
    n--;

    while (n--) {
        ll temp;
        cin >> temp;
        result += temp * sum;
        sum += temp;

        sum %= 1000000007;
        result %= 1000000007;
    }

    cout << result;
}
