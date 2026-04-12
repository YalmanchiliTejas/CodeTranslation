#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
using ll=long long;

int main()
{
    int r, g, b;
    
    cin >> r >> g >> b;
    
    auto number = 100 * r + 10 * g + b;
    
    printf("%s\n", number % 4 == 0 ? "YES" : "NO");
    
    return 0;
}
