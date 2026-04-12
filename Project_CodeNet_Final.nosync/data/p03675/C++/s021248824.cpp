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
#include <numeric>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> arr(n);
    vector<int> res(n);

    int back = n - 1;
    int front = 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i ++)
    {
        int k = arr[n - 1 - i];
        if (i % 2 == 1)
        {
            res[back] = k;
            back--;
        }
        else
        {
            res[front] = k;
            front++;
        }
    }

    for (auto& r : res)
        printf("%d ", r);

    return 0;
}