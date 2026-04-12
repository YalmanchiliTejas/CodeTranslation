#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int main()
{
    int x;
    cin >> x;

    cout << (x >= 30 ? "Yes" : "No") << endl;
    return 0;
}
