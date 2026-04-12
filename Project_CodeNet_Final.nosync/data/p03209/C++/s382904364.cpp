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

#include <boost/range/irange.hpp>
using boost::irange;

#include <boost/utility/string_ref.hpp>
using string_view = boost::string_ref;

#include <boost/function_output_iterator.hpp>


using namespace std;

template<class T, size_t N, class F>
struct compare_n
{
    F f;
    bool operator() (const T& t1, const T& t2)
    {
        return f(get<N>(t1), get<N>(t2));
    }
};
 
template<size_t N, class T>
auto make_less_n(const T&)
{
    using t = typename T::value_type;
    using less = std::less<typename tuple_element<N, t>::type>;
    return compare_n<t, N, less>();
}


static const vector<int64_t> nL = [](){
    vector<int64_t> v = {1};
    while(v.size() <= 50)
    {
        v.push_back(2 * v.back() + 3);
    }
    return v;
}();

static const vector<int64_t> nP = [](){
    vector<int64_t> v = {1};
    while(v.size() <= 50)
    {
        v.push_back(2 * v.back() + 1);
    }
    return v;
}();

int64_t f(int64_t n, int64_t x)
{
    if(x <= n)
        return 0;
    
    if(n == 0)
        return 1;
    
    if(x >= nL[n] - n)
        return nP[n];

    return f(n-1, x-1) + f(0, (x-1)-nL[n-1]) + f(n-1, (x-1-nL[n-1])-1);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int64_t n, x;
    cin >> n >> x;
    
    cout << f(n, x) << '\n';
    
    return 0;
}

