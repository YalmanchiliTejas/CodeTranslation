#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>

#define llong long long int

using namespace std;

int num_of_bits(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    if (n == 3 || n == 5 || n == 7) cout <<"YES" << endl;
    else cout << "NO" << endl;
    return 0;
}