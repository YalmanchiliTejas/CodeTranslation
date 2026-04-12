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

#include <boost/range/irange.hpp>
using boost::irange;

#include <boost/utility/string_ref.hpp>
using string_view = boost::string_ref;

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



int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    
    switch(x){
        case 7: case 5: case 3:
            cout << "YES\n"; break;
        default:
            cout << "NO\n"; break;
    }

    return 0;
}

