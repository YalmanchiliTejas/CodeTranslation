#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    auto sorted = arr;

    sort(sorted.begin(), sorted.end());

    int lh = arr.size() / 2 - 1;
    int rh = lh + 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sorted[lh])
            printf("%d\n", sorted[rh]);
        else
            printf("%d\n", sorted[lh]);
    }

    return 0;
}