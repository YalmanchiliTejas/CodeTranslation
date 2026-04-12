#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{
    lint n;
    scanf("%lld", &n);

    std::deque<lint> q;

    for (int i = 0; i < n; ++i)
    {
        lint a;
        scanf("%lld", &a);

        q.push_back(a);
    }

    std::sort(q.begin(), q.end());

    lint front, back;
    lint left, right;
    lint ans = 0;

    front = q.front();
    q.pop_front();
    back = q.back();
    q.pop_back();

    left = front;
    right = back;

    ans += abs(right - left);

    for (int i = 0; i < n - 2; ++i)
    {
        front = q.front();
        back = q.back();

        if (left < right)
        {
            lint lb = abs(left - back);
            lint rf = abs(right - front);
            if (lb > rf)
            {
                ans += lb;
                left = back;
                q.pop_back();
            }
            else
            {
                ans += rf;
                right = front;
                q.pop_front();
            }
        }
        else
        {
            lint lf = abs(left - front);
            lint rb = abs(right - back);
            if (rb > lf)
            {
                ans += rb;
                right = back;
                q.pop_back();
            }
            else
            {
                ans += lf;
                left = front;
                q.pop_front();
            }
        }
    }

    printf("%lld", ans);

    return 0;
}
