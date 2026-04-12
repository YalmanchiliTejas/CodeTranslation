#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long int ll;

#define INF (1e9)

int N, M;

int main() {
    cin >> N;

    if (N == 7 or N == 5 or N == 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
