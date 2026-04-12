#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

u64 N, M;

int main(int argc, char *argv[])
{
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    if (N >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
