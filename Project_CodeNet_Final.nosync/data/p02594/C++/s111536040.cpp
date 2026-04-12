#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

int main() {
    int x;
    cin >> x;

    if(x >= 30) {
        cout << "Yes"
             << "\n";
    } else {
        cout << "No" << endl;
    }
}