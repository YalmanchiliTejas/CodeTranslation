#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}





void oneCase () {
    int n;
    cin >> n;
    vector<string> lines(n);
    for (auto& l : lines) {
        cin >> l;
    }
    vector<int> minCounter(26, 1e9);

    for (int i = 0; i < n; ++i) {
        vector<int> cur(26);
        for (auto letter : lines[i]) {
            cur[int(letter) - int('a')] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            minCounter[i] = min(minCounter[i], cur[i]);
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < minCounter[i]; ++j) {
            cout << char('a' + i);
        }
    }
    cout << "\n";

}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}