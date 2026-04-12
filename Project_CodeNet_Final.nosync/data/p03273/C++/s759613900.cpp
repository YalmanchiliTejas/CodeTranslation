#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

int inputValue();
void inputArray(int *, int);
void inputVector(vector<int> *, int);
template <typename T> void output(T, int);
int gcd(int a, int b);

int main() {
    // source
    int h, w;
    cin >> h >> w;
    vector<string> a;
    rep(i, h) {
        string temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<int> index0, index1;

    rep(i, h) {
        bool judge = false;
        rep(j, w) {
            if (a[i][j] == '#') {
                judge = true;
            }
        }
        index0.push_back(judge);
    }
    rep(j, w) {
        bool judge = false;
        rep(i, h) {
            if (a[i][j] == '#') {
                judge = true;
            }
        }
        index1.push_back(judge);
    }

    rep(i, h) {
        if (!index0[i]) {
            continue;
        }
        rep(j, w) {
            if (index1[j]) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}

int inputValue() {
    int a;
    cin >> a;
    return a;
}

void inputArray(int *p, int a) {
    rep(i, a) { cin >> p[i]; }
}

void inputVector(vector<int> *p, int a) {
    rep(i, a) {
        int input;
        cin >> input;
        p->push_back(input);
    }
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

int gcd(int a, int b) {
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0) {
        return a;
    }
    return (b, b % a);
}
