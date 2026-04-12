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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    vector<int> ord(n);
    for (int i = 1; i < n; ++i) {
        ord[i] = i;
    }
    int counter = 0;
    do {
        int c = 0;
        for (int pos = 0; pos + 1 < n; ++pos) {
            c += edges[ord[pos]][ord[pos + 1]];
        }
        counter += (c == n - 1);
    } while (next_permutation(ord.begin() + 1, ord.end()));
    cout << counter << "\n";

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