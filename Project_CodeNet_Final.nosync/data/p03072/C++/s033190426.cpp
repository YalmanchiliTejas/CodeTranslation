#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <functional>
#include <bitset>
#include <queue>

#include <boost/range/irange.hpp>
using boost::irange;

#include <boost/utility/string_ref.hpp>
using string_view = boost::string_ref;

#include <boost/function_output_iterator.hpp>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    int max_h = 0;
    for(int i = 0; i < N; ++i)
    {
        int h;
        cin >> h;
        if(max_h <= h)
        {
            ++count;
        }
        max_h = max(max_h, h); 
    }
    cout << count << '\n';
    
    return 0;
}
