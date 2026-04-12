#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector < vector <int> > vvi;
const int HUGEI = 2147483647;  // (1 << 31) - 1
const ll HUGEL = 9223372036854775807;  // (1 << 63) - 1
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
    int n;
    vector <int> an, bn;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        an.push_back(a);
        bn.push_back(a);
    }
    sort(bn.begin(), bn.end());
    for (int i = 0; i < n; i++) {
        int a = an[i];
        if (a <= bn[n / 2 - 1]) {
            cout << bn[n / 2] << endl;
        } else {
            cout << bn[n / 2 - 1] << endl;
        }
    }
    return 0;
}
