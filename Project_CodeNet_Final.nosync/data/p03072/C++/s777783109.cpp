#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <fstream>
#include <iterator>
using namespace std;
// #include "prettyprint.hpp"

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    int MAX = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
        if (MAX <= H[i])
        {
            MAX = H[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
