#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

size_t count_mountains(std::vector<uint64_t>& mountains)
{
    assert(mountains.size() >= 1);

    std::vector<uint64_t> max_heights(mountains.size(), 0);
    for(size_t i = 1; i < mountains.size(); ++i)
    {
        max_heights[i] = max(max_heights[i-1], mountains[i-1]);
    }
    
    size_t count = 1; // 一番西の山は必ず見られる.
    for(size_t i = 1; i < mountains.size(); ++i)
    {
        if (max_heights[i] <= mountains[i]) {
            count++;
        }
    }

    return count;
}

int main ()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    size_t count = 0;
    cin >> count;

    std::vector<uint64_t> mountains(count, 0);
    for(size_t i = 0; i < count; ++i)
    {
        cin >> mountains[i];
        assert(1 <= mountains[i] && mountains[i] <= 100);
    }

    cout << count_mountains(mountains) << endl;

    return 0;
}
