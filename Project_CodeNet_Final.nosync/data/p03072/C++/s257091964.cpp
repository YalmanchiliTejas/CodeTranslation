#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
#include <climits>

using namespace std;

int main() {
    int n, c = 0;
    cin >> n;
    vector<int> h(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        int flag = 1;
        for (size_t j = 0; j < i; j++)
        {
            if(h[j] > h[i]) {
                flag = 0;
            }
        }
        if(flag) {
            c++;
        }
    }
    cout << c << endl;
}
